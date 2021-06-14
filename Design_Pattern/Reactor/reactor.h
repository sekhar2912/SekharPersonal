#ifndef REACTOR_REACTOR_H_
#define REACTOR_REACTOR_H_

#include <stdint.h>
#include <unistd.h>
#include <sys/epoll.h>

#include "singleton.h"
#include "timeheap.h"

namespace reactor
{
    struct Message
    {
        int32_t type;
        char data[256];
    };

    typedef unsigned int event_t;
    enum
    {
        kReadEvent    = 0x01,
        kWriteEvent   = 0x02,
        kErrorEvent   = 0x04,
        kEventMask    = 0xff
    };

    typedef int handle_t;
    
    class IEventHandler
    {
    public:
        virtual ~IEventHandler() {};
        virtual void OnMessage(const Message* msg) = 0;
        virtual handle_t GetHandle() const = 0;
        
    };

    class EventHandler : public IEventHandler
    {
    public:
        virtual void HandleRead() {}

        virtual void HandleWrite() {}

        virtual void HandleError() {}
        virtual void OnMessage(const Message* msg) {};
        virtual handle_t GetHandle() const {return NULL; };

    protected:

        EventHandler() {}

        virtual ~EventHandler() {}
    };

    class ReactorImplementation;

    class Reactor
    {
    public:

        Reactor();

        ~Reactor();

        int RegisterHandler(EventHandler * handler, event_t evt,reactor::Message* m_message = nullptr);

        int RemoveHandler(EventHandler * handler);

        void HandleEvents();

        int RegisterTimerTask(heap_timer* timerevent);
    private:

        Reactor(const Reactor &);
        Reactor & operator=(const Reactor &);

    private:

        ReactorImplementation * m_reactor_impl;
    };

} // namespace reactor
#endif // REACTOR_REACTOR_H_

