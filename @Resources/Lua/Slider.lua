
function Initialize()
    scale=SKIN:ParseFormula(SKIN:ReplaceVariables(SKIN:GetVariable('Scale')))
    updateRate=SKIN:GetVariable('UpdateRate')
    SName1=SKIN:GetMeter('SName1')
    SName2=SKIN:GetMeter('SName2')
    SArtist1=SKIN:GetMeter('SArtist1')
    SArtist2=SKIN:GetMeter('SArtist2')
    multiplier=tonumber(SKIN:GetVariable('RollSpeedMultiplier'))
    Reset()
end

function Reset()
    i=0
    j=0
    SKIN:Bang('!SetOption', 'SName1', 'X', 0)
    SKIN:Bang('!SetOption', 'SArtist1', 'X', 0)
    SKIN:Bang('!UpdateMeter', 'SName1')
    SKIN:Bang('!UpdateMeter', 'SArtist1')
    SKIN:Bang('!Redraw')
end

function Update()
    if cacheTrack ~= SKIN:GetMeasure(SKIN:GetVariable('PlayerType')..'Track'):GetStringValue() then
        Animate()
        print('Animating...')
    end
    cacheTrack = SKIN:GetMeasure(SKIN:GetVariable('PlayerType')..'Track'):GetStringValue()
end

function Animate()
    if SName1:GetW()>380*scale and SArtist1:GetW()<380*scale then
        i=i>=SName2:GetW() and 0 or i+1*multiplier
        SKIN:Bang('!SetOption', 'SName1', 'X', -i)
        SKIN:Bang('!UpdateMeter', 'SName1')
        SKIN:Bang('!Redraw')
        SKIN:Bang('[!Delay '..updateRate..'][!CommandMeasure '..SELF:GetName()..' Animate()]')
    elseif SName1:GetW()<=380*scale and SArtist1:GetW()>380*scale then
        j=j<=-SArtist2:GetW() and 0 or j-1*multiplier
        SKIN:Bang('!SetOption', 'SArtist1', 'X', j)
        SKIN:Bang('!UpdateMeter', 'SArtist1')
        SKIN:Bang('!Redraw')
        SKIN:Bang('[!Delay '..updateRate..'][!CommandMeasure '..SELF:GetName()..' Animate()]')
    elseif SName1:GetW()>380*scale and SArtist1:GetW()>380*scale then
        i=i<=-SName2:GetW() and 0 or i-1*multiplier
        j=j<=-SArtist2:GetW() and 0 or j-1*multiplier
        SKIN:Bang('!SetOption', 'SName1', 'X', i)
        SKIN:Bang('!SetOption', 'SArtist1', 'X', j)
        SKIN:Bang('!UpdateMeter', 'SName1')
        SKIN:Bang('!UpdateMeter', 'SArtist1')
        SKIN:Bang('!Redraw')
        SKIN:Bang('[!Delay '..updateRate..'][!CommandMeasure '..SELF:GetName()..' Animate()]')
    elseif i ~= 0 then
        Reset()
    end
end