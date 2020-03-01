PROGRAM pistes;

VAR
  levels, i : longint;
  mintime, maxtime : int64;
  times : array[1..1000000] of longint;
  input, output : text;

procedure merge(protomiso, middle, deuteromiso : longint);
var right, left, placed : longint; helpar : array[1..1000000] of longint;
begin
  left := protomiso;
  right := middle+1;
  placed := 1;
  while placed <= deuteromiso-protomiso+1 do
    if left > middle then
    begin
      helpar[placed] := times[right];
      right := right+1;
      placed := placed+1;
      end
    else
      if right > deuteromiso then
      begin
        helpar[placed] := times[left];
        left := left+1;
        placed := placed+1;
        end
      else
        if times[left] < times[right] then
        begin
          helpar[placed] := times[left];
          left := left+1;
          placed := placed+1;
          end
        else
        begin
          helpar[placed] := times[right];
          right := right+1;
          placed := placed+1;
          end;
  for i := 1 to placed-1 do
    times[i+protomiso-1] := helpar[i];
  end;

procedure mergesort(first,last : longint);
var middle : longint;
begin
  if first <> last then
  begin
    middle := (first+last) div 2;
    mergesort(first,middle);
    mergesort(middle+1,last);
    merge(first,middle,last);
    end;
  end;

BEGIN
  assign(input,'levels.in');
  reset(input);
  assign(output,'levels.out');
  rewrite(output);
  readln(input,levels);
  for i := 1 to levels do
    readln(input,times[i]);
  mergesort(1,levels);
  maxtime := 0;
  mintime := 0;
  for i := 1 to levels do
    mintime := mintime+times[i];
  for i := 1 to levels do
    maxtime := maxtime+(levels+2-i)*times[i];
  writeln(output,maxtime-mintime);
  close(input);
  close(output);
  end.
