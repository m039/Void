# Void

With **Void** I tried to answer the question: *"How someone could implements a game that doesn't depend on a particular game engine?"* or a preparation for *"Is it possible to swap a game engine on the fly?"*

Also, **Void** is a narrow copy of the second level of [Last Voyage](http://lastvoyage.co) that I used as a starting point.

Main goals:

* Make a solid foundation for a future game or a game engine.
* Try new structure of game projects that consists of 3 levels: Dirty, Clean, Pure.

Notes:

* Many ideas are borrowed from Unity or MonoGame.
* It is a concept, future of the project is unknown.
* I've written the same code for Unity, MonoGame and UrhoSharp. This is the fourth time, but with C++, libCinder and Raspberry Pi in mind.
* The project is tested on Mac, iOS and Raspberry Pi 3.

## Structure of the project

Project consists of 3 levels: Dirty, Clean, Pure.
 
### Dirty

It is a low-level of a project, which mostly consist of implementation code.

All code in `void-app` belong here.

### Clean

It is a proxy-level between Dirty and Pure.

All classes that are instantiated after `VoidGameHut`'s initialization belong here.

### Pure

It is a business-level where all preparations are made and we are ready to implement main part of a game.

All classes that are instantiated after `Game`'s initialization belong here.

## How to build

    # 1. Clone the repository
    git clone git@gitlab.com:m0391n/void-cinder.git --recursive
    
    # 2. Build Cinder
    pushd void-cinder/third-party/Cinder/ && mkdir build && cd build && cmake .. && make -j 8 && popd