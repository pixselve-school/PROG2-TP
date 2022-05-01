//
// Created by Mael Kerichard on 01/05/2022.
//

#ifndef ANTS_NOTIFICATION_H
#define ANTS_NOTIFICATION_H

#include <string>

class Notification {
public:
    explicit Notification(const std::string &text);

    const std::string &getText() const;

    Notification& operator=(const Notification &other);
private:
    std::string text;
};


#endif //ANTS_NOTIFICATION_H
