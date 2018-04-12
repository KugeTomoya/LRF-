#include "create_map.hpp"

#define error_diff 30
#define dis_gain 50.0

create_map::create_map(){
      //this->
      copy = cv::imread("/home/kuge/catkin_ws/src/opencv_test/src/coat2.jpg", 1);
      ox = 0;
      oy = 0;
      rev_rad = 0.0;
      ret_x = 0.0;
      ret_y = 0.0;
      //int step_check[1440];
      step = 0;
      ret_flag = 0;
      hit_flag = 0;
      //img = cv::Mat::zeros(1000, 1000, CV_8UC3);
}
void create_map::setup(){
    cv::resize(copy,img,cv::Size(), 0.5,0.5);
    cv::line(img, cv::Point(0, 353), cv::Point(1000,353), cv::Scalar(0,200,0), 3, 4);
    cv::line(img, cv::Point(353,0), cv::Point(353,1000), cv::Scalar(200,0,0), 3, 4);
}
void create_map::conversion(float *x,float *y){
    float buff_x;
    float buff_y;
    *y = -1.0**y;
    buff_x = *x;
    buff_y = *y;

    *x = buff_x*cosf(M_PI*1.0/4.0)-buff_y*sinf(M_PI*1.0/4.0);
    *y = buff_x*sinf(M_PI*1.0/4.0)+buff_y*cosf(M_PI*1.0/4.0);
}

void create_map::set_rev_rad(float deg){
    rev_rad = (M_PI/180)*(deg);
}

float create_map::ret_rev_rad(){
    return rev_rad;
}

void create_map::origin(float x,float y){
    ox = x/20;
    oy = y/20;
    sx = x;
    sy = y;
}

float create_map::return_ox(){
    return ox;
}

float create_map::return_oy(){
    return oy;
}
float create_map::return_sx(){
  return sx;
}
float create_map::return_sy(){
  return sy;
}


int create_map::return_flag(){
  return ret_flag;
}




void create_map::create(float dis,float rad,int step,int flag){
    float x = (dis*cosf(rad));
    float y = (dis*sinf(rad));
    float rev_x = x*cosf(ret_rev_rad())-y*sinf(ret_rev_rad());
    float rev_y = x*sinf(ret_rev_rad())+y*cosf(ret_rev_rad());

    ret_flag = 0;

    step = step;

    ret_x = rev_x;
    ret_y = rev_y;

    conversion(&rev_x,&rev_y);

    if(rev_x+return_sx() > 2050 && rev_y+return_sy() > 2050 && rev_x+return_sx() < 10700 && rev_y+return_sy() < 16170){

    if(rev_x+return_sx() + error_diff > 2050 && rev_x+return_sx() - error_diff < 2050 && rev_y+return_sy() > 2050 && rev_y+return_sy() < 16170 ){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 1;
    }
    else if((rev_x*dis_gain)+return_ox() + error_diff > 209 && (rev_x*dis_gain)+return_ox() - error_diff < 209 && (rev_y*dis_gain)+return_oy() > 454 && (rev_y*dis_gain)+return_oy()  < 606 ){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 2;
    }
    else if((rev_x*dis_gain)+return_ox() + error_diff > 372 && (rev_x*dis_gain)+return_ox() - error_diff < 372 && (rev_y*dis_gain)+return_oy()  > 101 && (rev_y*dis_gain)+return_oy() < 454){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 3;

    }
    else if((rev_x*dis_gain)+return_ox() + error_diff > 372 && (rev_x*dis_gain)+return_ox() - error_diff < 372 && (rev_y*dis_gain)+return_oy()  > 606 && (rev_y*dis_gain)+return_oy() < 706){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 4;

    }
    else if((rev_x*dis_gain)+return_ox() + error_diff > 535 && (rev_x*dis_gain)+return_ox() - error_diff < 535  && (rev_y*dis_gain)+return_oy()  > 706 && (rev_y*dis_gain)+return_oy() < 807){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 5;

    }

    else if((rev_y*dis_gain)+return_oy() + error_diff > 101 && (rev_y*dis_gain)+return_oy() - error_diff < 101 && (rev_x*dis_gain)+return_ox() > 101 && (rev_x*dis_gain)+return_ox() < 372){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
    //  cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
    ret_flag = 6;

    }
    else if((rev_y*dis_gain)+return_oy() + error_diff > 454 && (rev_y*dis_gain)+return_oy() - error_diff < 454 && (rev_x*dis_gain)+return_ox() > 209 && (rev_x*dis_gain)+return_ox() < 372){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 7;

    }
    else if((rev_y*dis_gain)+return_oy() + error_diff > 606 && (rev_y*dis_gain)+return_oy() - error_diff < 606 && (rev_x*dis_gain)+return_ox() > 209 && (rev_x*dis_gain)+return_ox() < 372){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 8;

    }
    else if((rev_y*dis_gain)+return_oy() + error_diff > 706 && (rev_y*dis_gain)+return_oy() - error_diff < 706 && (rev_x*dis_gain)+return_ox() > 209 && (rev_x*dis_gain)+return_ox() < 535){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 9;

    }
    else if((rev_y*dis_gain)+return_oy() + error_diff > 807 && (rev_y*dis_gain)+return_oy() - error_diff < 807 && (rev_x*dis_gain)+return_ox() > 101 && (rev_x*dis_gain)+return_ox() < 535){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(250,0,0), 1,8);
      cv::circle(img, cv::Point((rev_x*dis_gain)+return_ox(), (rev_y*dis_gain)+return_oy()), 2, cv::Scalar(0,0,200), 1, 4);
      ret_flag = 10;

    }
    else{
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(0,250,0), 1,8);
      ret_flag = 0;

    }

    //return return_flag;
  }
  else{
    cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(0,250,0), 1,8);
    ret_flag = 0;
  }
  /*  if((rev_y*dis_gain)+return_oy() < 100 || (rev_y*dis_gain)+return_oy() > 807){
      cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(0,0,250), 1,8);
    }
    else{
      if((rev_x*dis_gain)+return_ox() < 100){
        cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(0,0,250), 1,8);
      }else{
        cv::line(img, cv::Point((rev_x*dis_gain)+return_ox(),(rev_y*dis_gain)+return_oy()),cv::Point(return_ox(),return_oy()) , cv::Scalar(0,230,0), 1,8);
      }
    }*/
}

float create_map::judge(){
  float x = (return_x());
  float y = (return_y());
  switch (return_flag()){
    case 1://左
      return x;
      break;
    case 2:
      return x;
      break;
    case 3:
      return x;
      break;
    case 4:
      return x;
      break;
    case 5:
      return x;
      break;
    case 6:
      return x;
      break;
    case 7:
      return x;
      break;
    case 8:
      return x;
      break;
    case 9:
      return x;
      break;

    case 10:
      return x;
      break;
    case 0:
      return 0;
      break;
  }
}

float create_map::return_x(){
  return ret_x;
}
float create_map::return_y(){
  return ret_y;
}

void create_map::hit_switch(int *hit){
  hit_flag = *hit;
}
int create_map::ret_hit_flag(){
  return hit_flag;
}

void create_map::show(){
  //cv::line(img, cv::Point(0, 454),cv::Point(908,454), cv::Scalar(0,200,0), 3, 4);
  //cv::line(img, cv::Point(454,0), cv::Point(454,908), cv::Scalar(200,0,0), 3, 4);
  cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::imshow("drawing", img);
  cv::waitKey(1);
  img = cv::Scalar(0,0,0);
  cv::resize(copy,img,cv::Size(), 0.5,0.5);
  cv::line(img, cv::Point(372,101), cv::Point(372,454), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(209,454), cv::Point(209,606), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(372,606), cv::Point(372,706), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(535,706), cv::Point(535,807), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(101,101), cv::Point(101,807), cv::Scalar(250,255,0), 1, 4);

  cv::line(img, cv::Point(101,101), cv::Point(372,101), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(372,454), cv::Point(210,454), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(210,706), cv::Point(535,706), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(210,606), cv::Point(372,606), cv::Scalar(250,255,0), 1, 4);
  cv::line(img, cv::Point(101,807), cv::Point(535,807), cv::Scalar(250,255,0), 1, 4);
}
