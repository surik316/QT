#ifndef KLASS_H
#define KLASS_H
#include <iostream>
#include <QDir>
#include <QTimerEvent>
#include <QSocketNotifier>
#include <vector>
#include <set>
#include <QTimer>
#include <cmath>
#include <functional>
using namespace std;
class Klass: public QObject
{
  Q_OBJECT
  private:
    QDir dir;
    vector <pair<string, size_t>> vec;
    std::function<bool (const string&, const string&)> cmp ;
    set <string, decltype(cmp)> filesset;
    QTimer timer;
    QSocketNotifier m_n;
    void print(){
        bool flag = true;
        std::cout << std::endl << "{ ";
        for (const string& file: filesset) {
            if (!flag) {
                cout << ", ";
            } else {
                flag = false;
            }
            cout << file;
        }
        cout << " }";
        cout << endl <<"> " << flush;
    }
    void DeleteElement(){
        double rms;
        double summ = 0;
        bool flag = false;
        double min;
        int delete_element = 0;
        for(auto element: vec){
            summ += element.second;
        }
        summ = summ * 0.75 / vec.size();
        if (vec.size() == 0 || filesset.size() == 0){
            return;
        }
        if (filesset.size() == 1){
            filesset.clear();
            return;
        }
        for (size_t i = 0; i < vec.size(); i++){
            int size_file = vec[i].second;
            rms = sqrt((size_file - summ)*(size_file - summ));
            if (flag == false){
               min = rms;
               flag = true;
            }
            if (min > rms){
               min = rms;
               delete_element = i;
            }
        }
        filesset.erase(filesset.find(vec[delete_element].first));
        vec.erase(vec.begin() + delete_element);

    }
  public:
    explicit Klass(QObject *p = nullptr)
        :  QObject(p), m_n(fileno(stdin), QSocketNotifier::Read, this)
    {
        cmp = [&](const string& s1, const string& s2)->bool{
            int q1size = 0;
            int q2size = 0;
            for (size_t  i = 0; i < vec.size(); i++){
                string name = vec[i].first;
                if (s1 == name){
                    q1size = vec[i].second;
                }
                if (s2 == name){
                    q2size = vec[i].second;
                }
            }
            return q1size < q2size;
        };
          dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
          dir.setSorting(QDir::Size | QDir::Reversed);
          QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(timerEv()));
          start();
          QObject::connect(&m_n, SIGNAL(activated(int)), this, SLOT(read()));


    }
private slots:
  void timerEv(){
      DeleteElement();
      print();
  }
  void start(){
      QFileInfoList list = dir.entryInfoList();
      vec.clear();
      filesset.clear();
      vec.resize(list.size());
      filesset = set<string, decltype(cmp)> (cmp);
      for (int i = 0; i < list.size(); i++){
          QFileInfo fileInfo = list.at(i);
          vec[i].first = fileInfo.fileName().toStdString();
          vec[i].second = fileInfo.size();
          filesset.insert(vec[i].first);
       }
      print();
       if (timer.interval() == 0) {
               timer.start(3000);
           } else {
               timer.start();
       }
  }
    void read(){
        string cmd;
        getline(cin, cmd);
        if (cmd == "stop") {
               timer.stop();
           }
           else if (cmd == "start") {
               if (!timer.isActive()) {
                   timer.start();
               }
           } else if (cmd == "restart") {
               start();
           } else if (cmd == "exit") {
               emit all_signal();
           } else if (cmd.length() >=9 && cmd.substr(0, 7) == "timeout") {
               string str = cmd.substr(8);
               if (isdigit(str[0])) {
                   int num = stoi(str);
                   timer.start(num);
               }
           }
           if (cmd != "restart") {
               cout << "> " << std::flush;
           }

    }
    signals:
      void all_signal();


};
#endif // KLASS_H
