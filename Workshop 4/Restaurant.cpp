#include "Restaurant.h"

namespace sdds
{
    Restaurant::Restaurant(const sdds::Reservation* reservations[], size_t cnt){
        resNum = cnt;
        resDetails = new Reservation[cnt];
        for (size_t i = 0; i < cnt; i++){
            resDetails[i] = *reservations[i];
        }
    }

    size_t Restaurant::size() const{
        return resNum;
    }

    Restaurant::Restaurant(const Restaurant& obj){
        *this = obj;
    }

    Restaurant& Restaurant::operator=(const Restaurant& obj){
        if (this != &obj){
            resNum = obj.resNum;
            delete[] resDetails;
            resDetails = new Reservation[resNum];
            for (size_t i = 0; i < resNum; i++)
            {
                resDetails[i] = obj.resDetails[i];
            }
        }

        return *this;
    }

    Restaurant::Restaurant(Restaurant&& obj){
        *this = move(obj);
    }

    Restaurant& Restaurant::operator=(Restaurant&& obj){
        if (this != &obj){
            delete[] resDetails;
            resDetails = obj.resDetails;
            resNum = obj.resNum;
            obj.resDetails = nullptr;
            obj.resNum = 0;
        }
    }


    ostream& operator<<(ostream& ostr, Restaurant& obj){
        static size_t CALL_CNT;
        ++CALL_CNT;
        ostr << "--------------------------\n";
        ostr << "Fancy Restaurant (" << CALL_CNT << ")\n";
        ostr << "--------------------------\n";
        if (obj.resNum == 0){
            ostr << "This restaurant is empty!\n";
        }
        for (size_t i = 0; i < obj.resNum; i++){
            ostr << obj.resDetails[i];
        }
        ostr << "--------------------------\n";

        return ostr;
    }

    Restaurant::~Restaurant(){
        delete[] resDetails;
        resDetails = nullptr;
    }
}
