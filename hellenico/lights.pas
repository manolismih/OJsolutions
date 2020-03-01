PROGRAM lights;

TYPE
  sind = string[4];

VAR
  lampsnum, i, j, non, noff, sindiasmoinum, telika : integer;
  c : longint;
  lamps, finlamps : string[100];
  onn, off : array[1..2] of integer;
  oloisindiasmoi, sindiasmoi : array[1..16] of sind;
  telikes : array[1..16] of string[100];
  input, output : text;

procedure diamorfosi;
var ok : boolean;
begin
  ok := true;
  finlamps := lamps;
  if sindiasmoi[i][1] = '1' then
    for j := 1 to lampsnum do
      if finlamps[j] = '1' then
        finlamps[j] := '0'
      else
        finlamps[j] := '1';
  j := 1;
  if sindiasmoi[i][2] = '1' then
    while j <= lampsnum do
    begin
      if finlamps[j] = '1' then
        finlamps[j] := '0'
      else
        finlamps[j] := '1';
      j := j+2;
      end;
  j := 2;
  if sindiasmoi[i][3] = '1' then
    while j <= lampsnum do
    begin
      if finlamps[j] = '1' then
        finlamps[j] := '0'
      else
        finlamps[j] := '1';
      j := j+2;
      end;
  j := 1;
  if sindiasmoi[i][4] = '1' then
    while j <= lampsnum do
    begin
      if finlamps[j] = '1' then
        finlamps[j] := '0'
      else
        finlamps[j] := '1';
      j := j+3;
      end;
  for j := 1 to non do
    if finlamps[onn[j]] <> '1' then
      ok := false;
  if ok = true then
    for j := 1 to noff do
      if finlamps[off[j]] <> '0' then
        ok := false;
  if ok = true then
  begin
    telika := telika+1;
    telikes[telika] := finlamps;
    end;
  end;

function valid(sindiasmos : sind) : boolean;
var a : sind; value, tval, code, i : integer;
begin
  tval := 0;
  for i := 1 to 4 do
  begin
    a := copy(sindiasmos,i,1);
    val(a,value,code);
    tval := tval+value;
    end;
  if (tval > c) or ((tval mod 2) <> (c mod 2)) then
    valid := false
  else
    valid := true;
  end;


procedure generate;
begin
  oloisindiasmoi[1] := '0000';
  oloisindiasmoi[2] := '0001';
  oloisindiasmoi[3] := '0010';
  oloisindiasmoi[4] := '0011';
  oloisindiasmoi[5] := '0100';
  oloisindiasmoi[6] := '0101';
  oloisindiasmoi[7] := '0110';
  oloisindiasmoi[8] := '0111';
  oloisindiasmoi[9] := '1000';
  oloisindiasmoi[10] := '1001';
  oloisindiasmoi[11] := '1010';
  oloisindiasmoi[12] := '1011';
  oloisindiasmoi[13] := '1100';
  oloisindiasmoi[14] := '1101';
  oloisindiasmoi[15] := '1110';
  oloisindiasmoi[16] := '1111';
  sindiasmoinum := 0;
  for i := 1 to 16 do
    if valid(oloisindiasmoi[i]) = true then
    begin
      sindiasmoinum := sindiasmoinum+1;
      sindiasmoi[sindiasmoinum] := oloisindiasmoi[i];
      end;
  end;

BEGIN
  telika := 0;
  assign (input,'lamps.in');
  reset (input);
  assign (output,'lamps.out');
  rewrite (output);
  readln (input,lampsnum);
  readln (input,c);
  j := 0;
  repeat
    j := j+1;
    read(input,i);
    if i <> -1 then
      onn[j] := i;
    until i = -1;
  non := j-1;
  readln (input);
  j := 0;
  repeat
    j := j+1;
    read(input,i);
    if i <> -1 then
      off[j] := i;
    until i = -1;
  noff := j-1;
  generate;

  for i := 1 to lampsnum do
    lamps := lamps + '1';
  for i := 1 to sindiasmoinum do
    diamorfosi;
  for i := 1 to telika do
    for j := i+1 to telika do
      if telikes[j] < telikes[i] then
      begin
        lamps := telikes[i];
        telikes[i] := telikes[j];
        telikes[j] := lamps;
        end;
  for i := 1 to telika do
    writeln(output,telikes[i]);
  close(output);
  END.
