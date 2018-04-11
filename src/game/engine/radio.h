/**
* @file
*
* @author CCHyper
*
* @brief <todo>
*
* @copyright Redalert++ is free software: you can redistribute it and/or
*            modify it under the terms of the GNU General Public License
*            as published by the Free Software Foundation, either version
*            2 of the License, or (at your option) any later version.
*            A full copy of the GNU General Public License can be found in
*            LICENSE
*/
#pragma once

#ifndef RADIO_H
#define RADIO_H

#include "always.h"
#include "gametypes.h"
#include "mission.h"
#include "smartptr.h"

class TechnoClass;
class FootClass;

// A invalid target instance parsed into Transmit_Message() as a default param.
extern target_t NullRadioTarget;

class RadioClass : public MissionClass
{
public:
    RadioClass(RTTIType type, int id);
    RadioClass(RadioClass const &that);
    RadioClass(NoInitClass const &noinit) : MissionClass(noinit) {}
    virtual ~RadioClass(void);

    virtual BOOL Limbo(void) override;
    virtual RadioMessageType Receive_Message(RadioClass *radio, RadioMessageType message, target_t &target) override;
    virtual void Code_Pointers(void) override;
    virtual void Decode_Pointers(void) override;
    virtual RadioMessageType Transmit_Message(RadioMessageType message, target_t &target = NullRadioTarget, RadioClass *radio = nullptr);
    virtual RadioMessageType Transmit_Message(RadioMessageType message, RadioClass *radio);

    //TODO, rename!
    bool const Radio_Valid(void) const
    {
        return Radio != nullptr;
    }

    TechnoClass *Radio_As_Techno(void) const
    {
        if ( Radio_Valid() ) {
            return (TechnoClass *)&Radio;
        }
        return nullptr;
    }

    FootClass *Radio_As_Foot(void) const
    {
        if ( Radio_Valid() ) {
            return (FootClass *)&Radio;
        }
        return nullptr;
    }

    static char const *Message_From(RadioMessageType message);
	static RadioMessageType RadioClass::From_Message(char const *message);

private:
    static char const *Messages[RADIO_COUNT];

public:

    RadioMessageType ReceivedMessage;		//0x37	//name subject to change!
    RadioMessageType TransmittedMessage;	//0x38	//name subject to change!
    RadioMessageType LastMessage;		    //0x39
    SmartPtr<ObjectClass> Radio;			//0x3A
};

#endif // RADIO_H
