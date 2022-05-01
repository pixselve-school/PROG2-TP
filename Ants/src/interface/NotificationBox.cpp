//
// Created by Mael Kerichard on 01/05/2022.
//

#include "NotificationBox.h"
#include "../utils/Renderer.h"

std::unique_ptr<NotificationBox> NotificationBox::instance;


void NotificationBox::deleteOldestNotification() {
    if (notifications.empty())
        return;
    notifications.pop_back();
}

NotificationBox::NotificationBox()= default;

void NotificationBox::update() const {
    int i = 0;
    for (const auto &notification: notifications) {
        Renderer::getInstance()->drawString(Vector2<float>(5, 5) + Vector2<float>(0, i), notification.getText());
        i += 15;
    }

}

void NotificationBox::addNotification(const Notification &notification) {
    if (notifications.size() > 5) {
        deleteOldestNotification();
    }
    notifications.insert(notifications.begin(), notification);
}

NotificationBox *NotificationBox::getInstance() {
    return instance.get();
}

void NotificationBox::initialize() {
    instance =  std::unique_ptr<NotificationBox>(new NotificationBox());
}
