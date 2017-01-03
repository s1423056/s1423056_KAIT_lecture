#include "colors.inc"
#include "shapes.inc"
#include "golds.inc"

camera{
  location < 0,50,-100>
  look_at <0,0,50>
  angle 35
}

light_source{<-3,50,-10> color White}
light_source{<5,90,-15> color 2.5*White}
    
object {
  Plane_XZ
  pigment{checker color Red color Blue}
  scale 10.0
  translate<0,0,0>
}

#declare FRAME_N = 90;
#declare V0 = 25;
#declare Angle = radians(85);
#declare Vx = V0*cos(Angle);
#declare Vy = V0*sin(Angle);
#declare g = 9.8;
#declare Time = 0.0;
#declare Tmax = 30;
#declare Time_interval = Tmax/FRAME_N;
#declare Nt = 2*Vy/g;
#declare Bt = 0.0;
#declare LoopMax = Tmax*clock + Time_interval/2;
#declare PosX = -Nt*Vx/2-10;

#while(Time <= LoopMax)
  #if(Time >= Nt)
    #declare Vy = Vy*0.8;
    #declare Bt = Nt;
    #declare Nt = Nt+2*Vy/g;
  #end
  
  #if((Time > Tmax*clock-Time_interval/2)&(Time<Tmax*clock+Time_interval/2))
    object{
      Sphere
      texture{T_Gold_1A}
      scale 3
      #declare Ty = Vy*(Time-Bt)-g*(Time-Bt)*(Time-Bt)/2;
      #if(Ty<0)
        #declare Ty = 0;
      #end
      #declare Tx = Vx*Time+PosX;
      translate<Tx,Ty,Tx>
      translate<0,3,0>
    }
  #end
  #declare Time = Time+Time_interval;
#end