#include <Rcpp.h> // provides access to Rcpp library
#include <iostream> // provides access to std library
#include <string> // provides access to string library

class Shape{

public:
double length;
double height;


Shape(){}

};

class Rectangle : public Shape{
public:  
  Rectangle() : Shape() {}

  public:
  //this->length: points to length within base class, etc.
  double area(){
    return this->length * this->height;
  }
};
  
class Triangle : public Shape{
public:
  Triangle() : Shape() {}
  
  public:
  double area(){
    return 0.5 * this->length * this->height;
  } 
};

// [[Rcpp::export]]
double calculate_areas(std::string shape, double length, double height){
  
  double out = 0;
  
  if(shape == "rectangle"){
      Rectangle rect;
      rect.length = length;
      rect.height = height;
      out = rect.area();
  } else if (shape == "triangle") {
      Triangle tri;
      tri.length = length;
      tri.height = height;
      out = tri.area();
  } else {
      Rcpp::Rcout << "Invalid shape" << std::endl;
  }
  return out;
}
