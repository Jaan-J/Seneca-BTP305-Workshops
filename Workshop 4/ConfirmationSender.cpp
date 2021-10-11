#include "ConfirmationSender.h"

namespace sdds
{
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj){
        *this = obj;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& obj){
      if (this != &obj){
          total = obj.total;
          resConf = new const Reservation * [total];
          for (size_t i = 0; i < total; i++){
              resConf[i] = obj.resConf[i];
          }
        }

        return *this;
   }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& obj){
        *this = move(obj);
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& obj){
        if (this != &obj){
            total = obj.total;
            resConf = obj.resConf;
            obj.resConf = nullptr;
            obj.total = 0;
        }

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
        bool flag = false;
        for (size_t i = 0; i < total; i++){
            if (resConf[i] == &res){
                flag = true;
            }
        }

        if (flag == false){
            const Reservation** temp = nullptr;
            temp = new const Reservation * [total + 1];
            for (size_t i = 0; i < total; ++i){
                temp[i] = resConf[i];
            }

            temp[total] = &res;
            delete[] resConf;
            resConf = temp;
            total++;
        }

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
        bool flag = false;
        size_t index = 0;
        for (size_t i = 0; i < total; ++i){
            if (resConf[i] == &res){
                index = i;
                i = total;
                flag = true;
            }
        }

        if (flag == true){
            const Reservation** temp = nullptr;
            temp = new const Reservation * [total - 1];
            for (size_t i = 0; i < total - 1; i++){
                if (i < index){
                    temp[i] = resConf[i];
                }
                else{
                    temp[i] = resConf[i + 1];
                }
            }
            delete[] resConf;
            resConf = temp;
            --total;
        }

        return *this;
    }

    std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& obj){
        ostr << "--------------------------\n";
        ostr << "Confirmations to Send\n";
        ostr << "--------------------------\n";
        if (obj.total == 0){
            ostr << "There are no confirmations to send!\n";
        }

        for (size_t i = 0; i < obj.total; i++){
            if (obj.resConf[i] != nullptr){
                ostr << *obj.resConf[i];
            }
        }

        ostr << "--------------------------\n";
        return ostr;
    }

    ConfirmationSender::~ConfirmationSender(){
        delete[] resConf;
        resConf = nullptr;
    }
}
