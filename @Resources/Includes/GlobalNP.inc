[mState]
Measure=NowPlaying
PlayerName=#NPName#
PlayerType=State
IfCondition=mState = (#Control# = 1 ? 1 : 100)
IfTrueAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!UpdateMeasure mHide][!Redraw]
IfCondition2=mState = (#Control# = 1 ? 2 : 100)
IfTrueAction2=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!UpdateMeasure mHide][!Redraw]
IfCondition3=mState = (#Control# = 1 ? 0 : 100)
IfTrueAction3=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!UpdateMeasure mHide][!Redraw]
IfConditionMode=0
OnchangeAction=[!CommandMeausre MagickMeter "Update"][!UpdateMeter *]
DynamicVariables=1
UpdateDivider=(1000/#Rm.Updiv#)



[mHide]
Measure=calc
Formula=#AutoHide#
ifcondition=(mHide = 1) && (mState = 0)
iftrueaction=[!HideFade]
IfFalseAction=[!ShowFade]
UpdateDivider=-1

[mCover]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Cover
Substitute="":"#@#Images\Default.png"
UpdateDivider=(1000/#Rm.Updiv#)

[mArtist]
Measure=NowPlaying
PlayerName=[mState]
OnchangeAction=[!UpdateMeasureGroup Music][!UpdateMeter *][!Redraw]
PlayerType=Artist
Substitute="":"Fetching...",",.*":""
UpdateDivider=(1000/#Rm.Updiv#)

[mTrack]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Title
Substitute="":"Fetching..."
UpdateDivider=(1000/#Rm.Updiv#)

[mProgress]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Progress
Substitute="NaN":"1"
DynamicVariables=1
Disabled=(1 - #Prog#)
UpdateDivider=(1000/#Rm.Updiv#)

[mCurrentPosition]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Position
Disabled=(1 - #Prog#)
UpdateDivider=(1000/#Rm.Updiv#)

[mLength]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Duration
Disabled=(1 - #Prog#)
UpdateDivider=(1000/#Rm.Updiv#)


[mRepeat]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Repeat
IfCondition=mRepeat = 1
IfTrueAction=[!SetOption Repeat MeterStyle Repeat1][!UpdateMeter Repeat][!Redraw]
IfCondition2=mRepeat = 2
IfTrueAction2=[!SetOption Repeat MeterStyle Repeat2][!UpdateMeter Repeat][!Redraw]
IfCondition3=mRepeat = 0
IfTrueAction3=[!SetOption Repeat MeterStyle Repeat0][!UpdateMeter Repeat][!Redraw]
DynamicVariables=1
UpdateDivider=1
Disabled=(1 - #Repeat#)
UpdateDivider=(1000/#Rm.Updiv#)

[mShuffle]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Shuffle
IfCondition=mShuffle = 1
IfTrueAction=[!SetOption Shuffle MeterStyle Shuffle1][!UpdateMeter Shuffle][!Redraw]
IfCondition2=mShuffle = 0
IfTrueAction2=[!SetOption Shuffle MeterStyle Shuffle0][!UpdateMeter Shuffle][!Redraw]
DynamicVariables=1
UpdateDivider=1
Disabled=(1 - #Shuffle#)
UpdateDivider=(1000/#Rm.Updiv#)

[mHeart]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Rating
IfCondition=mHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"]
Disabled=(1 - #Heart#)
UpdateDivider=(1000/#Rm.Updiv#)