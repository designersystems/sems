/*
 * $Id: PySemsDialog.h,v 1.26.2.1 2005/09/02 13:47:46 rco Exp $
 * 
 * Copyright (C) 2006 iptego GmbH
 *
 * This file is part of sems, a free SIP media server.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include "PySemsB2ABDialog.h"
#include "PySemsUtils.h"
PySemsB2ABDialog::PySemsB2ABDialog()
    : playlist(this),
      user_timer(NULL)
{
}

PySemsB2ABDialog::PySemsB2ABDialog(AmDynInvoke* user_timer)
    : playlist(this),
      user_timer(user_timer)
{
}

PySemsB2ABDialog::~PySemsB2ABDialog()
{
}

void PySemsB2ABDialog::onSessionStart(const AmSipRequest& req)
{
    DBG("PySemsB2ABDialog::onSessionStart\n");
    setInOut(&playlist,&playlist);
    AmB2ABCallerSession::onSessionStart(req);
}

void PySemsB2ABDialog::process(AmEvent* event) 
{
    DBG("PySemsB2ABDialog::process\n");

    AmAudioEvent* audio_event = dynamic_cast<AmAudioEvent*>(event);
    if(audio_event && audio_event->event_id == AmAudioEvent::noAudio){

	callPyEventHandler("onEmptyQueue", NULL);
	event->processed = true;
    }
    
    AmPluginEvent* plugin_event = dynamic_cast<AmPluginEvent*>(event);
    if(plugin_event && plugin_event->name == "timer_timeout") {

	callPyEventHandler("onTimer", "i", plugin_event->data.get(0).asInt());
	event->processed = true;
    }

    if (!event->processed)
      AmB2ABCallerSession::process(event);

    return;
}

