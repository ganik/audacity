/**********************************************************************

Audacity: A Digital Audio Editor

TimeTrackUI.cpp

Paul Licameli split from TrackPanel.cpp

**********************************************************************/

#include "../../../TimeTrack.h"
#include "TimeTrackControls.h"
#include "TimeTrackVRulerControls.h"

#include "../../../HitTestResult.h"
#include "../../../TrackPanelMouseEvent.h"
#include "../../../Project.h"

#include "../../ui/EnvelopeHandle.h"

UIHandlePtr TimeTrack::DetailedHitTest
(const TrackPanelMouseState &st,
 const AudacityProject *pProject, int, bool)
{
   return EnvelopeHandle::TimeTrackHitTest
      ( mEnvelopeHandle, st.state, st.rect, pProject, Pointer<TimeTrack>(this) );
}

std::shared_ptr<TrackControls> TimeTrack::GetControls()
{
   return std::make_shared<TimeTrackControls>( Pointer( this ) );
}

std::shared_ptr<TrackVRulerControls> TimeTrack::GetVRulerControls()
{
   return std::make_shared<TimeTrackVRulerControls>( Pointer( this ) );
}
