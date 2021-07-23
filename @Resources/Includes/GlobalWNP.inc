
[mCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\Default.png
CoverPath=#@#Images\Cover.png
UpdateDivider=(1000/#Rm.Updiv#)

[mState]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
IfCondition=mState = (#Control# = 1 ? 1 : 100)
IfTrueAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!UpdateMeasure mHide][!Redraw]
IfCondition2=mState = (#Control# = 1 ? 2 : 100)
IfTrueAction2=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!UpdateMeasure mHide][!Redraw]
IfCondition3=mState = (#Control# = 1 ? 0 : 100)
IfTrueAction3=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!UpdateMeasure mHide][!Redraw]
DynamicVariables=1
UpdateDivider=(1000/#Rm.Updiv#)

[mHide]
Measure=calc
Formula=#AutoHide#
ifcondition=(mHide = 1) && (mState = 0)
iftrueaction=[!HideFade]
IfFalseAction=[!ShowFade]
UpdateDivider=-1

[mArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
RegExpSubstitute=1
Substitute=",.*":""
UpdateDivider=(1000/#Rm.Updiv#)

[mTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
OnChangeAction=[!UpdateMeter *][!Redraw]
UpdateDivider=(1000/#Rm.Updiv#)

[mProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=(1000/#Rm.Updiv#)
Disabled=(1 - #Prog#)

[mProgressPer]
Measure=Calc
Formula=mProgress/100
UpdateDivider=(1000/#Rm.Updiv#)

[mCurrentPosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=(1000/#Rm.Updiv#)
Disabled=(1 - #Prog#)

[mLength]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=(1000/#Rm.Updiv#)
Disabled=(1 - #Prog#)

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
UpdateDivider=(1000/#Rm.Updiv#)
Disabled=(1 - #Repeat#)

[mShuffle]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Shuffle
IfCondition=mShuffle = 1
IfTrueAction=[!SetOption Shuffle MeterStyle Shuffle1][!UpdateMeter Shuffle][!Redraw]
IfCondition2=mShuffle = 0
IfTrueAction2=[!SetOption Shuffle MeterStyle Shuffle0][!UpdateMeter Shuffle][!Redraw]
DynamicVariables=1
UpdateDivider=(1000/#Rm.Updiv#)
Disabled=(1 - #Shuffle#)

[mHeart]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Rating
IfCondition=mHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"]
UpdateDivider=(1000/#Rm.Updiv#)
Disabled=(1 - #Heart#)