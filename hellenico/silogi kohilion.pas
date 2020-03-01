PROGRAM kohiliacontest;
VAR
  diastauroseisnum, maxkohilia, j, k : longint;
  sigrisi : array[1..100000] of longint;
  diastauroseis : array[1..1000,1..3] of longint;
  input, output : text;

procedure bestroute(curmonopati,curkohilia : longint);
var i : longint; found : boolean;
begin
  found := false;
  for i := 1 to diastauroseisnum do
    if diastauroseis[i,1] = curmonopati then
    begin
      found := true;
      bestroute(diastauroseis[i,2],curkohilia+diastauroseis[i,3]);
      end;
    if found = false then
    begin
      j := j + 1;
      sigrisi[j] := curkohilia;
      end;
end;

BEGIN
  assign(input,'contest.in');
  reset(input);
  assign(output,'contest.out');
  rewrite(output);
  readln(input,diastauroseisnum);
  diastauroseisnum := diastauroseisnum-1;
  for j := 1 to diastauroseisnum do
    readln(input,diastauroseis[j,1],diastauroseis[j,2],diastauroseis[j,3]);
  j := 0;
  bestroute(1,0);
  maxkohilia := 0;
  for k := 1 to j do
    if sigrisi[k]>maxkohilia then
      maxkohilia :=sigrisi[k];
  writeln(output,maxkohilia);
  close (input);
  close (output);
  END.
