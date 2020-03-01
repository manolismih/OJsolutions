PROGRAM makis;

TYPE
  array100000 = array[1..3,1..100000] of longint;
  bigarray = array[1..3,1..100000] of array of longint;
  smallarray = array[1..100000] of boolean;
  array100000ptr = ^array100000;
  bigarrayptr = ^bigarray;
  smallarrayptr = ^smallarray;

VAR
  pinakas : array100000ptr;
  helpar : bigarrayptr;
  newpinakas, newhelpar : array100000;
  delstiles, delnumbers : smallarrayptr;
  problem : smallarray;
  input, output : text;
  n, i, j, k, min, problemnum, depth : longint;

function check : boolean;
begin
  check := true;
  for i := 1 to n do
    if not delnumbers^[i] then
      if (helpar^[1,i,0] = 0) or (helpar^[2,i,0] = 0) or (helpar^[3,i,0] = 0) then
      begin
        check := false;
        delnumbers^[i] := true;
        for k := 1 to 3 do
          for j := 1 to helpar^[k,i,0] do
            delstiles^[helpar^[k,i,j]] := true;
        end;
  end;

procedure dfsid(depth,stili : longint);
var i : longint;
begin
  if problemnum = 0 then
  begin
    writeln(output,min);
    close(output);
    halt;
    end;

  if depth = 0 then
    exit;

  for i := stili to n do
  begin
    for k := 1 to 3 do
      newhelpar[k,newpinakas[k,i]] := newhelpar[k,newpinakas[k,i]] - 1;
    for k := 1 to 3 do
      if (newhelpar[1,newpinakas[k,i]] = newhelpar[2,newpinakas[k,i]]) and (newhelpar[1,newpinakas[k,i]] = newhelpar[3,newpinakas[k,i]]) then
        if problem[newpinakas[k,i]] then
        begin
          problem[newpinakas[k,i]] := false;
          problemnum := problemnum-1;
          end
        else
      else
        if problem[newpinakas[k,i]] = false then
        begin
          problem[newpinakas[k,i]] := true;
          problemnum := problemnum+1;
          end;
    min := min+1;

    dfsid(depth-1,stili+1);

    for k := 1 to 3 do
      newhelpar[k,newpinakas[k,i]] := newhelpar[k,newpinakas[k,i]] + 1;
    for k := 1 to 3 do
      if (newhelpar[1,newpinakas[k,i]] = newhelpar[2,newpinakas[k,i]]) and (newhelpar[1,newpinakas[k,i]] = newhelpar[3,newpinakas[k,i]]) then
        if problem[newpinakas[k,i]] then
        begin
          problem[newpinakas[k,i]] := false;
          problemnum := problemnum-1;
          end
        else
      else
        if problem[newpinakas[k,i]] = false then
        begin
          problem[newpinakas[k,i]] := true;
          problemnum := problemnum+1;
          end;
    min := min-1;
    end;
  end;


BEGIN
  assign(input,'physics.in');
  reset(input);
  assign(output,'physics.out');
  rewrite(output);
  new(pinakas);
  new(helpar);
  new(delstiles);
  new(delnumbers);
  for i := 1 to 3 do
    for j := 1 to 100000 do
    begin
      setlength(helpar^[i,j],1);
      helpar^[i,j,0] := 0;
      end;
  for i := 1 to 100000 do
  begin
    delstiles^[i] := false;
    delnumbers^[i] := false;
    end;

  readln(input,n);
  for i := 1 to 3 do
  begin
    for j := 1 to n do
    begin
      read(input,pinakas^[i,j]);
      helpar^[i,pinakas^[i,j],0] := helpar^[i,pinakas^[i,j],0]+1;
      setlength(helpar^[i,pinakas^[i,j]] , helpar^[i,pinakas^[i,j],0]+1);
      helpar^[i,pinakas^[i,j],helpar^[i,pinakas^[i,j],0]] := j;
      end;
    readln(input);
    end;

  repeat
    until check;

  for i := 1 to n do
    if delstiles^[i] then
    begin
      min := min+1;
      for k := 1 to 3 do
        helpar^[k,pinakas^[k,i],0] := helpar^[k,pinakas^[k,i],0] - 1;
      end;

  i := 0;
  j := 0;
  repeat
    j := j+1;
    if not delstiles^[j] then
    begin
      i := i+1;
      for k := 1 to 3 do
        newpinakas[k,i] := pinakas^[k,j];
      end;
    until j = n;
  n := i;
  dispose(pinakas);

  for i := 1 to 3 do
    for j := 1 to 100000 do
      newhelpar[i,j] := helpar^[i,j,0];
  dispose(helpar);
  dispose(delstiles);
  dispose(delnumbers);

  for i := 1 to 100000 do
    if (newhelpar[1,i] <> newhelpar[2,i]) or (newhelpar[1,i] <> newhelpar[3,i]) then
    begin
      problem[i] := true;
      problemnum := problemnum+1;
      end;

  for depth := 0 to n do
    dfsid(depth,1);

  END.
