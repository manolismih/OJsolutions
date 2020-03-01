program downloads;

var
  arxeia, i, k, l : integer;
  lipseis : array[1..100,1..2] of real;
  xronos, bandwidth, proigxronos, proigbandwidth : real;
  input, output : text;

begin
  assign (input, 'downloads.in');
  assign (output, 'downloads.out');
  reset (input);
  rewrite (output);
  readln (input, arxeia);

  for i := 1 to arxeia do
    begin
    read (input,lipseis[i,1]);
    readln (input,lipseis[i,2])
    end;

  bandwidth := 0;
  for i := 1 to arxeia do
    bandwidth := bandwidth + lipseis[i,1];

  for i := 1 to arxeia do
    begin
    proigxronos := 32767;
    for k := i to arxeia do
      if lipseis[k,2] < proigxronos then
        begin
        proigxronos := lipseis[k,2];
        l := k
        end;
    proigbandwidth := lipseis[i,1];
    proigxronos := lipseis[i,2];
    lipseis[i,1] := lipseis[l,1];
    lipseis[i,2] := lipseis[l,2];
    lipseis[l,1] := proigbandwidth;
    lipseis[l,2] := proigxronos
    end;

  xronos := 0;
    for i := 1 to arxeia-1 do
    begin
    xronos := xronos + lipseis[i,2];
    for k := i+1 to arxeia do begin
      lipseis[k,2] := lipseis[k,2]-lipseis[i,2];
      end;
    proigbandwidth := lipseis[i+1,1];
    lipseis[i+1,1] := lipseis[i+1,1]+lipseis[i,1];
    lipseis[i+1,2] := lipseis[i+1,2]*proigbandwidth/lipseis[i+1,1];
    end;

  xronos := xronos + lipseis[arxeia,2];
  write (output, round(xronos));
  close (input);
  close (output);
  end.
