[mState]
Measure=NowPlaying
PlayerName=#NPName#
PlayerType=State
IfCondition=mState = 1
IfTrueAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw]
IfCondition2=mState = 2
IfTrueAction2=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw]
IfCondition3=mState = 0
IfTrueAction3=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw]
IfConditionMode=0
OnchangeAction=[!CommandMeausre MagickMeter "Update"][!UpdateMeter *]
DynamicVariables=1

[mCover]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Cover
Substitute="":"#@#Images\Default.png"

[mArtist]
Measure=NowPlaying
PlayerName=[mState]
OnchangeAction=[!UpdateMeasureGroup Music][!UpdateMeter *][!Redraw]
PlayerType=Artist
Substitute="":"Fetching..."

[mTrack]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Title
Substitute="":"Fetching..."

[mProgress]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Progress
Substitute="NaN":"1"
DynamicVariables=1

[mCurrentPosition]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Position

[mLength]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Duration

[mHeart]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Rating
IfCondition=mHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"]