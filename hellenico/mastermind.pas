PROGRAM mastermind;

VAR
  n, i, j, eidi, slots, max : integer;
  limits : array[1..10,1..7] of byte;
  sindiasmos : array[0..5] of byte;
  input, output : text;

procedure next;
begin
  sindiasmos[slots] := sindiasmos[slots]+1;
  i := slots;
  while sindiasmos[i] > eidi do
  begin
    sindiasmos[i] := 1;
    i := i-1;
    sindiasmos[i] := sindiasmos[i]+1;
    end;
  end;

procedure check;
var olososta, sosta, k : byte; found : boolean; copyl, copys : array[1..5] of byte;
begin
  i := 0;
  repeat
    olososta := 0;
    sosta := 0;
    i := i+1;
    for j := 1 to slots do
    begin
      copyl[j] := limits[i,j];
      copys[j] := sindiasmos[j];
      end;
    for j := 1 to slots do
      if copys[j] = copyl[j] then
      begin
        olososta := olososta+1;
        copyl[j] := 0;
        copys[j] := 0;
        end;

    if olososta = limits[i,slots+1] then
      for j := 1 to slots do
        if copys[j] <> 0 then
        begin
        found := false;
        k := 0;
        repeat
          k := k+1;
          if copys[j] = copyl[k] then
          begin
            found := true;
            copyl[k] := 0;
            copys[j] := 0;
            end;
          until (found = true) or (k = slots);
        if found = true then
          sosta := sosta+1;
        end;
    until ((olososta <> limits[i,slots+1]) or (sosta <> limits[i,slots+2])) or (i = n);
    if (olososta = limits[i,slots+1]) and (sosta = limits[i,slots+2]) then
      max := max+1;
  end;

BEGIN
  assign(input,'mastermind.in');
  reset(input);
  assign(output,'mastermind.out');
  rewrite(output);

  readln(input,n,eidi,slots);
  for i := 1 to n do
    for j := 1 to slots+2 do
      read(input,limits[i,j]);

  for i := 0 to slots-1 do
    sindiasmos[i] := 1;
  sindiasmos[slots] := 0;
  max := 0;

  repeat
    next;
    if sindiasmos[0] = 1 then
      check;
    until sindiasmos[0] = 2;

  writeln(output,max);
  close(output);
  END.
