program hiddentreasure;
{$linklib hiddenlib}
uses hiddenlib;

var
  koutia : integer;
  protomiso, deuteromiso : longint;

begin
  deuteromiso := getN;
  protomiso := 1;
  repeat
    koutia := compare(protomiso,deuteromiso);
    if koutia = 0 then
      if ishidden(deuteromiso div 100) = 1 then
        halt;
    if koutia = 1 then
      deuteromiso := deuteromiso div 2;
    if koutia = -1 then
      protomiso := deuteromiso div 2;
  until 1=0;
end.
