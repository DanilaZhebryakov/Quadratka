#ifndef ASSERTP_H_INCLUDED
#define ASSERTP_H_INCLUDED

#define assertp(cond) {                                                                                                     \
    if(!(cond)) {                                                                                                           \
        fprintf(stderr,"Assertion failed: %s \nFile:%s \nLine:%d \nFunc:%s\n",#cond,__FILE__,__LINE__,__PRETTY_FUNCTION__); \
        exit(EXIT_FAILURE);                                                                                                 \
    }                                                                                                                       \
}


#endif // ASSERTP_H_INCLUDED
