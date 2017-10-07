Program Aerolinias;
uses crt;
const
     n=100;

type
    t_dato=record
           n_vuelo:string[30];
           destino:string[30];
           hora_salida:real;
           duracion:real;
           linea_aerea:string[50];
           costo_pasaje:real;
           end;
    t_vector=array[1..n]of t_dato;

var
   opcion:0..7;
   ultimo,i,posicion:byte;
   vector:t_vector;
   bandera:boolean;
   buscado, buscado2, buscado3:string[30];
   mayor:real;

procedure inicializar(var v:t_vector; var ult:byte);
          begin
               fillchar(v, sizeof(v), #0);
               ult:=0;
          end;

procedure cargar(var v:t_vector; ult:byte);
          var
             tecla:char;
          begin
             writeln('ingrese tecla para cargar, n para salir');
             readln(tecla);
             while(tecla<>'n')and(ult<n)do
                begin
                  inc(ult);
                  writeln('ingrese los siguientes datos: numero de vuelo, destino, hora de salida, duracion, linea aerea, costo de pasaje');
                  with v[ult] do
                       begin
                         readln(n_vuelo);
                         readln(destino);
                         readln(hora_salida);
                         readln(duracion);
                         readln(linea_aerea);
                         readln(costo_pasaje);
                       end;
                  writeln('continua?, n para salir');
                  readln(tecla);
                end;
          end;

procedure busqueda_secuencial(var v:t_vector; ult:byte; buscado:string[30]; var pos:byte; var band:boolean);  //busqueda y listado de vuelos con destino a Amsterdam, por medio de busqueda secuencial, item(a).
          var
             i:integer;
          begin
               for i:=1 to ult do
                 begin
                   if (v[i].destino=buscado)then
                      begin
                           pos:=i;
                           if (v[i].linea_aerea='AEROLINIAS ARGENTINAS')then
                              begin
                                band:=true;
                              end;
                      end;
                 end;
          end;


procedure busqueda_secuencial2(var v:t_vector; ult:byte; var may:real);  //busqueda de vuelo de mayor duracion, por medio de busqueda secuencial, item(b).
          var
             i:integer;
          begin
               may:=v[1].duracion;
               for i:=2 to ult do
                 begin
                   if (v[ult].duracion>may)then
                      begin
                           may:=v[i].duracion;
                      end;
                 end;
          end;

procedure ordenar(var v:t_vector; ult:byte);  //ordenar el listado por linea aerea y por destino, por metodo burbuja.
          var                                 //se llama en el procedimiento listar.
             i,j:byte;
             aux:t_dato;
          begin
               for i:=1 to ult-1 do
                   begin
                     for j:=1 to ult-i do
                         begin
                           if (v[j].linea_aerea+v[j].destino>v[j+1].linea_aerea+v[j+1].destino)then  //concatenacion de caracteres.
                              begin
                                   aux:=v[j];
                                   v[j]:=v[j+1];
                                   v[j+1]:=aux;
                              end;
                         end;
                   end;
          end;


procedure listar(var vec:t_vector; ulti:byte); //listado de vuelos por linea aerea y por destino, item (c).
          var
             i:byte;
          begin
               for i:=1 to ulti do;
                   begin
                        with vec[i] do
                             begin
                                  writeln(n_vuelo, destino, hora_salida, duracion, linea_aerea, costo_pasaje);
                             end;
                   end;
          end;

procedure ordenar_xnvuelos(var v:t_vector; ult:byte); //ordenar el listado por numero de vuelo, por metodo burbuja.
          var                                        //se llama en el procedimiento de busqueda binaria por vuelo.
             i,j:byte;
             aux:t_dato;
          begin
               for i:=1 to ult-1 do
                   begin
                     for j:=1 to ult-i do
                         begin
                           if (v[j].n_vuelo>v[j+1].n_vuelo)then
                              begin
                                   aux:=v[j];
                                   v[j]:=v[j+1];
                                   v[j+1]:=aux;
                              end;
                         end;
                   end;
          end;


procedure bbin_vuelos(var v:t_vector; ult:byte; buscado:string[30]; var pos:byte); //busqueda del vuelo AA900 y ver que destino tiene, por medio de busqueda binaria, item(d).
          var
             pri,ul,med:byte;
          begin
               pri:=1;
               ul:=ult;
               pos:=0;
               while(pri<=ul)and(pos=0)do
                  begin
                       med:=(pri+ul)div 2;
                       if (v[med].n_vuelo=buscado) then
                          pos:=med
                       else
                          begin
                               if (v[med].n_vuelo>buscado) then
                                   ul:=med-1
                               else
                                   begin
                                        pri:=med+1;
                                   end;
                          end;
                  end;
          end;

procedure bbin_vuelos1(var v:t_vector; ult:byte; buscado:string[30]; var pos:byte); //busqueda de todos los pasajes vendidos por la aerolinia IBERIA para su incremento del 10%, por medio de busqueda binaria, item(e).
          var
             pri,ul,med:byte;
          begin
               pri:=1;
               ul:=ult;
               pos:=0;
               while(pri<=ul)and(pos=0)do
                  begin
                       med:=(pri+ul)div 2;
                       if (v[med].linea_aerea=buscado) then
                               pos:=med
                       else
                          begin
                               if (v[med].linea_aerea>buscado) then
                                       ul:=med-1
                               else
                                   begin
                                        pri:=med+1;
                                   end;
                          end;
                  end;
          end;

begin
     writeln('1-inicializar');
     writeln('2-cargar');
     writeln('3-consulta-lista de vuelos con destino Amsterdam');
     writeln('4-consulta-vuelo de mayor duracion');
     writeln('5-consulta-lista de vuelos ordenados por linea aerea y por destinos');
     writeln('6-consulta-determinar si el vuelo AA900 tiene como destino ROMA');
     writeln('7-consulta-incremento de los pasajes');
     writeln('0-salir');
     repeat
           writeln('eligir opcion');
           readln(opcion);
           case(opcion)of

                         1:inicializar(vector,ultimo);
                         2:cargar(vector, ultimo);
                         3:begin
                           bandera:=false;
                           posicion:=0;
                           writeln('ingrese destino que desea buscar');
                           readln(buscado);
                           for i:= 1 to ultimo do
                               begin
                                 busqueda_secuencial(vector, ultimo, buscado, posicion, bandera);
                                 if posicion <>0 then
                                    begin
                                      writeln(vector[posicion].n_vuelo);
                                      writeln(vector[posicion].destino);
                                      writeln(vector[posicion].hora_salida);
                                      writeln(vector[posicion].duracion);
                                      writeln(vector[posicion].linea_aerea);
                                      writeln(vector[posicion].costo_pasaje);
                                    end;
                               end;
                           if bandera then
                                     begin
                                       writeln('la linea Aerolinas Argentinas vuela ese destino');
                                     end;
                           end;
                         4:begin
                            posicion:=0;
                            busqueda_secuencial2(vector, ultimo, mayor);
                            writeln('vuelos de mayor duracion');
                            for i:=1 to ultimo do
                              begin
                                if vector[i].duracion=mayor then
                                   begin
                                      with vector[i] do
                                         begin
                                           writeln(n_vuelo, destino, hora_salida, duracion, linea_aerea, costo_pasaje);
                                         end;
                                   end;
                              end;
                           end;
                         5:begin
                            ordenar(vector, ultimo);
                            listar(vector, ultimo);
                           end;
                         6:begin
                            posicion:=0;
                            ordenar_xnvuelos(vector, ultimo);
                            buscado2:='AA900';
                            bbin_vuelos(vector,ultimo ,buscado2, posicion);
                            if posicion<>0 then
                               begin
                                 if (vector[posicion].destino='ROMA') then
                                    begin
                                     with vector[posicion] do
                                       begin
                                        writeln('el vuelo AA900 se dirige a ROMA');
                                        writeln(n_vuelo, destino, hora_salida, duracion,linea_aerea, costo_pasaje);
                                       end;
                                    end
                                 else
                                     begin
                                      writeln('no hay ningun vuelo AA900');
                                     end;
                               end;
                            end;
                         7:begin
                            posicion:=0;
                            ordenar(vector, ultimo);
                            buscado3:='IBERIA';
                            for i:=1 to ultimo do
                              begin
                                bbin_vuelos1(vector, ultimo,buscado3, posicion);
                                if posicion<>0 then
                                  begin
                                   vector[posicion].costo_pasaje:=vector[posicion].costo_pasaje*0.10;
                                   with vector[posicion] do
                                     begin
                                      writeln(n_vuelo, destino, hora_salida, duracion,linea_aerea, costo_pasaje);
                                     end;
                                  end;
                              end;
                           end;
                         end;
     until opcion=0;
end.
