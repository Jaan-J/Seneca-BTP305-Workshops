#include "Reservation.h"
namespace sdds
{

    void Reservation::update(int day, int time){
       this->resDay = day;
       this->resHour = time;
    }

    Reservation::Reservation(const string& res){

        string bufferID, bufferName, bufferEmail, bufferPpl, bufferDay, bufferHour;
        string bufferRes = res;

        bufferID = bufferRes.substr(0, bufferRes.find(':'));
        bufferRes.erase(0, bufferRes.find(':') + 1);
        bufferName = bufferRes.substr(0, bufferRes.find(','));
        bufferRes.erase(0, bufferRes.find(',') + 1);
        bufferEmail = bufferRes.substr(0, bufferRes.find(','));
        bufferRes.erase(0, bufferRes.find(',') + 1);
        bufferPpl = bufferRes.substr(0, bufferRes.find(','));
        bufferRes.erase(0, bufferRes.find(',') + 1);
        bufferDay = bufferRes.substr(0, bufferRes.find(','));
        bufferRes.erase(0, bufferRes.find(',') + 1);
        bufferHour = bufferRes.substr(0, bufferRes.find(','));
        bufferRes.erase(0, bufferRes.find(',') + 1);

        bufferID.erase(0, bufferID.find_first_not_of(' '));
        bufferID.erase(bufferID.find_last_not_of(' ') + 1);
        bufferName.erase(0, bufferName.find_first_not_of(' '));
        bufferName.erase(bufferName.find_last_not_of(' ') + 1);
        bufferEmail.erase(0, bufferEmail.find_first_not_of(' '));
        bufferEmail.erase(bufferEmail.find_last_not_of(' ') + 1);

        resID = bufferID;
        resName = bufferName;
        resEmail = bufferEmail;
        resNumPpl = stoi(bufferPpl);
        resDay = stoi(bufferDay);
        resHour = stoi(bufferHour);
    }

    ostream& operator<<(ostream& ostr, const Reservation& obj){
        ostr << "Reservation " << right << std::setw(10) << obj.resID << ": ";
        ostr << std::setw(20) << obj.resName;
        ostr << string(2, ' ') << left << std::setw(20) << "<" + obj.resEmail + ">";
        ostr << string(4, ' ');

        if (obj.resHour >= 6 && obj.resHour <= 9){
            ostr << "Breakfast";
        }
        else if (obj.resHour >= 11 && obj.resHour <= 15){
            ostr << "Lunch";
        }
        else if (obj.resHour >= 17 && obj.resHour <= 21){
            ostr << "Dinner";
        }
        else{
            ostr << "Drinks";
        }

        ostr << " on " << "day " << obj.resDay << " @ " << obj.resHour << ":00" << " for " << obj.resNumPpl << (obj.resNumPpl <= 1 ? " person" : " people") << "." << endl;

        return ostr;

    }
}
