//
// Created by Mael Kerichard on 01/05/2022.
//

#ifndef ANTS_NOTIFICATIONBOX_H
#define ANTS_NOTIFICATIONBOX_H


#include <vector>
#include "Notification.h"
#include "../ants/Agent.h"

class NotificationBox {
private:
    std::vector<Notification> notifications;



    void deleteOldestNotification();

    NotificationBox();

protected:
    static std::unique_ptr<NotificationBox> instance;

public:
    void update() const;

    void addNotification(const Notification& notification);

    static NotificationBox* getInstance();

    static void initialize();

};


#endif //ANTS_NOTIFICATIONBOX_H
