#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        const Reservation** resConf = nullptr;
        size_t total = 0;
    public:
        ConfirmationSender() = default;
        ConfirmationSender& operator +=(const Reservation& res);
        ConfirmationSender& operator -=(const Reservation& res);

        ConfirmationSender(const ConfirmationSender&);
        ConfirmationSender& operator=(const ConfirmationSender&);

        ConfirmationSender(ConfirmationSender&&);
        ConfirmationSender& operator=(ConfirmationSender&&);

        ~ConfirmationSender();

        friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
    };
}

#endif
