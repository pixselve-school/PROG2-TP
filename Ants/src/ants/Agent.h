//
// Created by Mael Kerichard on 08/04/2022.
//

#ifndef ANTS_AGENT_H
#define ANTS_AGENT_H


#include "../ant-environment/Environment.h"

typedef enum {
    running, destroy
} Status;

class Agent : public Environment::LocalizedEntity {
private:
    static std::set<Agent *> agents;
    Status status;

public:
    Status getStatus() const {
        return status;
    }

    void setStatus(Status status) {
        this->status = status;
    }


    Agent(Environment *environment, const Vector2<float> &position,
          float radius = Environment::LocalizedEntity::defaultRadius()) : LocalizedEntity(environment,
                                                                                          position, radius),
                                                                          status(running) {
        agents.insert(this);

    }

    virtual void update() = 0;

    /**
     * Lorsqu’un agent est dans l’état running, sa méthode update() est appelée. Lorsqu’un agent est dans l’état destroy, il doit être détruit par un appel à delete sur son pointeur et sortir de l’ensemble des agents actifs.
     */
    static void simulate() {
        for (auto iter = agents.begin(); iter != agents.end();) {
            switch ((*iter)->getStatus()) {
                case running:
                    (*iter)->update();
                    iter++;
                    break;
                case destroy:
                    delete (*iter);
                    iter = agents.erase(iter);
                    break;
            }
        }
    }

    /**
     * Détruire tous les agents encore actifs en fin de la simulation
     */
    static void finalize() {
        for (auto item: agents) {
            delete item;
        }
    }


};


#endif //ANTS_AGENT_H
