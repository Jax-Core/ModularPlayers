mediaPlayers = {'AIMP', 'CAD', 'WMP', 'iTunes', 'Winamp', 'WebNowPlaying'}
-- mediaPlayers = {'CAD', 'WebNowPlaying'}

function checkMediaAuto()
    currentPlayer = nil
    for i = 1, 6 do
        if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() == 1 then
            currentPlayer = mediaPlayers[i]
            break
        end
    end
    if currentPlayer == nil then
        for i = 1, 6 do
            if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() == 2 then
                currentPlayer = mediaPlayers[i]
                break
            end
        end
    end
    if currentPlayer == nil then currentPlayer = SKIN:GetVariable('NowPlayingMedia') end

    checkingPlayer = currentPlayer

    checkingPlayerState = SKIN:GetMeasure('state'..checkingPlayer):GetValue()

    -- print(checkingPlayer, checkingPlayerState)
    if checkingPlayerState ~= 0 then
        if checkingPlayer == 'WebNowPlaying' then
            SKIN:Bang('[!EnableMeasureGroup WNP][!DisableMeasureGroup NP]')
            SKIN:Bang('[!SetVariable PlayerType WNP]')

            if SKIN:GetVariable('Shuffle') == 0 then
                SKIN:Bang('[!DisableMeasure wnpShuffle]')
            end

            if SKIN:GetVariable('Repeat') == 0 then
                SKIN:Bang('[!DisableMeasure wnpRepeat]')
            end

            if SKIN:GetVariable('Heart') == 0 then
                SKIN:Bang('[!DisableMeasure wnpHeart]')
            end

            if SKIN:GetVariable('Prog') == 0 then
                SKIN:Bang('[!DisableMeasure wnpProgress][!DisableMeasure wnpCurrentPosition][!DisableMeasure wnpLength]')
            end
        else 
            SKIN:Bang('[!EnableMeasureGroup NP][!DisableMeasureGroup WNP]')
            SKIN:Bang('[!SetVariable PlayerType NP]')

            if SKIN:GetVariable('Shuffle') == 0 then
                SKIN:Bang('[!DisableMeasure npShuffle]')
            end

            if SKIN:GetVariable('Repeat') == 0 then
                SKIN:Bang('[!DisableMeasure npRepeat]')
            end

            if SKIN:GetVariable('Heart') == 0 then
                SKIN:Bang('[!DisableMeasure npHeart]')
            end

            if SKIN:GetVariable('Prog') == 0 then
                SKIN:Bang('[!DisableMeasure npProgress][!DisableMeasure npCurrentPosition][!DisableMeasure npLength]')
            end
        end
    else
        SKIN:Bang('[!DisableMeasureGroup NP][!DisableMeasureGroup WNP]')
    end
        
    
    SKIN:Bang('[!SetVariable NowPlayingMedia '..checkingPlayer..']')
    SKIN:Bang('[!UpdateMeasureGroup Music][!UpdateMeterGroup Music]')

    if tonumber(SKIN:GetVariable('Control')) == 1 then
        if checkingPlayerState == 1 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Pause"][!UpdateMeter PlayPause]')
        elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
        elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
        end
    end
    
    if tonumber(SKIN:GetVariable('AutoHide')) == 1 then
        if checkingPlayerState ~= 0 then 
            SKIN:Bang('[!ShowFade]')
        else
            SKIN:Bang('[!HideFade]')
        end
    end

    if checkingPlayerState == 0 then
        SKIN:Bang('[!HideMeterGroup Music][!UpdateMeterGroup Music]')
    else
        SKIN:Bang('[!ShowMeterGroup Music][!UpdateMeterGroup Music]')
    end
    
    SKIN:Bang('[!Redraw]')
end


function checkMediaModern()

    checkingPlayerState = SKIN:GetMeasure('stateModern'):GetValue()

    if SKIN:GetVariable('Shuffle') == 0 then
        SKIN:Bang('[!DisableMeasure modernShuffle]')
    end

    if SKIN:GetVariable('Repeat') == 0 then
        SKIN:Bang('[!DisableMeasure modernRepeat]')
    end

    if SKIN:GetVariable('Heart') == 0 then
        SKIN:Bang('[!DisableMeasure modernHeart]')
    end

    if SKIN:GetVariable('Prog') == 0 then
        SKIN:Bang('[!DisableMeasure modernProgress][!DisableMeasure modernCurrentPosition][!DisableMeasure modernLength]')
    end
        
    SKIN:Bang('[!UpdateMeasureGroup Music]')

    if tonumber(SKIN:GetVariable('Control')) == 1 then
        if checkingPlayerState == 1 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Pause"][!UpdateMeter PlayPause]')
        elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
        elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
        end
    end
    
    if tonumber(SKIN:GetVariable('AutoHide')) == 1 then
        if checkingPlayerState ~= 0 then 
            SKIN:Bang('[!ShowFade]')
        else
            SKIN:Bang('[!HideFade]')
        end
    end

    if checkingPlayerState == 0 then
        SKIN:Bang('[!HideMeterGroup Music][!UpdateMeterGroup Music]')
    else
        SKIN:Bang('[!ShowMeterGroup Music][!UpdateMeterGroup Music]')
    end
    
    SKIN:Bang('[!Redraw]')
end