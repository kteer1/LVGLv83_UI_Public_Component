#ifndef ___kPAGE_H__
#define ___kPAGE_H__


#define SCREEN_PAGELIST_MAX         5



enum{
    kPAGE_SCREEN_0,
    kPAGE_SCREEN_1,

    kPAGE_SCREEN_END = kPAGE_SCREEN_1,
};






// void* Get_PageUID(unsigned short fuid);
void kPage_Init(void* param);
#endif // PAGE_H


