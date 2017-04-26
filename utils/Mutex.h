/*
 * =====================================================================================
 *
 *       Filename:  Mutex.h
 *
 *    Description:  A simple mutex wrapper
 *
 *        Version:  1.0
 *        Created:  04/09/17 18:54:14
 *       Revision:  0.1 - Creation
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __MUTEX_H
#define  __MUTEX_H

#include <sys/types.h>
#include <pthread.h>

class Mutex {
public:
    enum {
        PRIVATE = 0,
        SHARED
    };

    Mutex();
    Mutex(int type);
    ~Mutex();

    int lock();
    void unlock();
    int trylock();

    class Autolock {
    public:
        inline Autolock(Mutex &mutex) : mLock(mutex) {mLock.lock();}
        inline Autolock(Mutex *mutex) : mLock(*mutex) {mLock.lock();}
        inline ~Autolock() {mLock.unlock();}
    private:
        Mutex &mLock;
    };

private:
    // Can not be copied
    Mutex(const Mutex &);
    Mutex &operator = (const Mutex&);
    pthread_mutex_t mMutex;
};

inline Mutex::Mutex()
{
    pthread_mutex_init(&mMutex, NULL);
}

inline Mutex::Mutex(int type)
{
    if (type == SHARED) {
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(&mMutex, &attr);
        pthread_mutexattr_destroy(&attr);
    } else {
        pthread_mutex_init(&mMutex, NULL);
    }
}

inline Mutex::~Mutex()
{
    pthread_mutex_destroy(&mMutex);
}

inline int Mutex::lock()
{
    return pthread_mutex_lock(&mMutex);
}

inline void Mutex::unlock()
{
    pthread_mutex_unlock(&mMutex);
}

inline int Mutex::trylock()
{
    return pthread_mutex_trylock(&mMutex);
}

typedef Mutex::Autolock AutoMutex;

#endif   /* __MUTEX_H */
