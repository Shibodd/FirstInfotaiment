#ifndef LOGLINECONTAINER_HPP
#define LOGLINECONTAINER_HPP

#include <gui_generated/containers/logLineContainerBase.hpp>

class logLineContainer : public logLineContainerBase
{
public:
    logLineContainer();
    virtual ~logLineContainer() {}

    virtual void initialize();
protected:
};

#endif // LOGLINECONTAINER_HPP
