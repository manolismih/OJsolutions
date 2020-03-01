PROGRAM physics;

TYPE
  katastasi = record
    data, deleted : array of longint;
    next : pointer;
    end;
  pointer = ^katastasi;

VAR
  input, output : text;
  pinakas : array[1..3,1..100000] of longint;
  helpar : array[1..3,0..100000] of array of longint;
  deleted : array[1..100000] of boolean;
  tobe_deleted : array of array of longint;
  n, i, j, k, min, mindeleted : longint;
  head, node : pointer;

BEGIN
  assign(input,'physics.in');
  reset(input);
  assign(output,'physics.out');
  rewrite(output);
  readln(input,n);
  for i := 1 to 3 do
  begin
    for j := 1 to n do
    begin
      read(input,pinakas[i,j]);
      setlength(helpar[i,pinakas[i,j]],length(helpar[i,pinakas[i,j]])+1);
      helpar[i,pinakas[i,j],length(helpar[i,pinakas[i,j]])-1] := j;
      end;
    readln(input);
    end;

  for j := 1 to n do
  begin
    min := 2000000;
    for i := 1 to 3 do
      if length(helpar[i,j]) < min then
        min := length(helpar[i,j]);

    if min = 0 then
      for i := 1 to 3 do
      begin
        for k := 0 to length(helpar[i,j])-1 do
        begin
          mindeleted := mindeleted+1;
          deleted[helpar[i,j,k]] := true;
          end;
        setlength(helpar[i,j],0);
        end
    else
      for i := 1 to 3 do
        if length(helpar[i,j]) > min then
        begin
          setlength(tobe_deleted,length(tobe_deleted)+1);
          setlength(tobe_deleted[length(tobe_deleted)-1],length(helpar[i,j])+1);
          tobe_deleted[length(tobe_deleted)-1,0] := length(helpar[i,j]) - min;
          for k := 0 to length(helpar[i,j])-1 do
            tobe_deleted[length(tobe_deleted)-1,k+1] := helpar[i,j,k];
          end;
    end; {end of for j := 1 to n loop}

  min := 0; {counts how many tobe_deleted elements were resolved}
  for i := length(tobe_deleted)-1 downto 0 do
  begin
    k := 0; {counts how many tobedeleted[i] elements were resolved}
    j := length(tobe_deleted[i]);
    while (tobe_deleted[i,0] > 0) and (j-1 > 0) do
    begin
      j := j-1;
      if deleted[tobe_deleted[i,j]] then
      begin
        tobe_deleted[i,0] := tobe_deleted[i,0]-1;
        k := k+1;
        tobe_deleted[i,j] := tobe_deleted[i,length(tobe_deleted[i])-k];
        end;
      end;
    if tobe_deleted[i,0] = 0 then
    begin
      min := min+1;
      tobe_deleted[i] := tobe_deleted[length(tobe_deleted)-min];
      end
    else
      setlength(tobe_deleted[i],length(tobe_deleted[i])-k);
    end;
  setlength(tobe_deleted,length(tobe_deleted)-min);





  END.
