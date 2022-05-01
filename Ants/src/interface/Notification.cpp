//
// Created by Mael Kerichard on 01/05/2022.
//

#include "Notification.h"

Notification::Notification(const std::string &text) : text(text) {}

const std::string &Notification::getText() const {
    return text;
}

Notification &Notification::operator=(const Notification &other) = default;
