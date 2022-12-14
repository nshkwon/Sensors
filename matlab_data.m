

clc

clear

delete(instrfindall)



% serial

s2 = serial('COM3', 'BaudRate', 9600);

fopen(s2);

time = 0;


x_limit = 1000;
% x axis
start_x = 0;
done_x = 1000;

start_y=0;
done_y=400;

%xlim([start_x done_x]);
ylim([start_y done_y]);


fileID=fopen('sine_ta4.csv','w');  
fprintf(fileID, '%s,%s,%s,%s ,%s,%s\n','senser1','timems','senser2','timems','senser3','timems')





for a = 1:x_limit



   % save string data

   accel = (fscanf(s2));
   
   

   % tokenizer 

   [data, tf] = str2num(accel);
  
   
   
    time = time+100;
 
  
  % xlim([0,x_limit]);

   if a>2
     
       
     %  figure
       plot(time,data(1), 'rx');

       hold on;

       plot(time, data(3), 'g*');

       hold on;

       plot(time, data(5), 'b.');

       hold on;

       

       drawnow;
       

    fprintf('\t%d\t%d\t%d\t%d\r\n', data(1),data(3), data(5));
    fprintf(fileID, '%d,%d,%d,%d,%d,%d\n', data(1),data(2), data(3), data(4), data(5), data(6));
    
   end
   

end

a = 0;

clf;

fclose(s2);

delete(instrfindall)
%https://mc10sw.tistory.com/13