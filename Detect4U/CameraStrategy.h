
#ifndef CAMERASTRATEGY_H
#define CAMERASTRATEGY_H

class CameraStrategy {
public:
    virtual void do_strat(bool t = true) = 0;
    virtual ~CameraStrategy(){}
};

#endif // CAMERASTRATEGY_H
