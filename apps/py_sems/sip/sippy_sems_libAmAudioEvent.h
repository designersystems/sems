/*
 * Interface header file.
 *
 * Generated by SIP 4.5.2 (4.5.2) on Wed Mar 28 22:59:14 2007
 */

#ifndef _py_sems_libAmAudioEvent_h
#define _py_sems_libAmAudioEvent_h

#line 29 "AmAudio.sip"
#include "../../../core/AmAudio.h"
#line 13 "sippy_sems_libAmAudioEvent.h"

#define sipClass_AmAudioEvent             sipModuleAPI_py_sems_lib.em_types[5]
#define sipCast_AmAudioEvent              sipType_py_sems_lib_AmAudioEvent.td_cast
#define sipForceConvertTo_AmAudioEvent    sipType_py_sems_lib_AmAudioEvent.td_fcto

#define sipEnum_AmAudioEvent_EventType              sipModuleAPI_py_sems_lib.em_enums[1]

extern sipTypeDef sipType_py_sems_lib_AmAudioEvent;


class sipAmAudioEvent : public AmAudioEvent
{
public:
    sipAmAudioEvent(int);
    sipAmAudioEvent(const AmAudioEvent&);
    ~sipAmAudioEvent();

public:
    sipWrapper *sipPySelf;

private:
    sipAmAudioEvent(const sipAmAudioEvent &);
    sipAmAudioEvent &operator = (const sipAmAudioEvent &);
};

#endif
