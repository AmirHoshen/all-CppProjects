//
// Created by miros on 25/07/2020.
//
#pragma once

namespace itertools{
    class range{

    protected:
        int _begin , _end;

    public:
        range(int begin, int end): _begin(begin), _end(end){}

        class iterator{
        private:
            int _current;
        public:
            iterator(int c=0): _current(c){}

        };
    };
}
