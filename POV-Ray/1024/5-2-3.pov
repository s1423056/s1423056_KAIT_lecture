#include"colors.inc"
#include"shapes.inc"

camera{
  location<10,10,10>
  look_at<0,0,0>
  angle 50
}

light_source{ <10,10,20> color White }
light_source{ <10,10,-10> color White }


background {color White}

#declare deco = 
  object{
    Disk_Y
    scale<1.2,0.2,1.2>
    pigment{ color Blue }
  }

#declare body = union{
  object{
    Cone_Y
    scale <1,0.5,1>
    rotate <-180,0,0>
    pigment{ color Red }
  } 
  object{
    Disk_Y
    translate <0,2,0>
    scale <1,0.25,1>
    pigment{ color Red }
  }
}

#declare shaft = union{
  object{
    Cone_Y
    rotate <-180,0,0>
    translate <0,-5,0>
    scale <0.25,0.25,0.25>
    pigment { color Yellow }
  }
  object{
    Disk_Y
    scale <0.25,1,0.25>
    pigment { color Yellow }
  }
}

#declare top =union{
  object{
    deco 
    translate<0,0.5,0>
  }
  object{
    body
  }
  object{
    shaft
  }
}

object{
  top
  scale<1.5,1.5,1.5>
  translate<-3,0,0>
}
object{
  top
  rotate<0,0,300>
  translate<5,0,0>
}
object{
  top
  scale<1.2,1.2,1.2>
  rotate<40,0,10>
  translate<1,0,5>
}
object{
  top
  rotate<-40,0,10>
  translate<2,0,-5>
}