#include <iostream>
using namespace std;
#include <vector>

class Review {
  public: 
    void setRatingAndComment(int rating, string comment) {
      this->rating = rating;
      this->comment = comment;
    }
    string getComment() const { return comment; }
    int getRating() const {return rating;}
  private:
    int rating = -1;
    string comment = "uninit";
};

class Reviews {
  public:
    int averageRating() const;
    void inputReviews();
    void printComments();
  private:
    vector<Review> list; 
};

void Reviews::inputReviews() {

}

int Reviews::averageRating() const {
  int size = list.size();
  int total = 0;
  for(int i = 0; i < size; i++) {
      total += list.at(i).getRating();
  }
  return (size == 0) ? 0 : total/size;
}

int main(){
  Reviews yelp;


  return 0;
}


//9.13

//input reviews, print comments for rating, get average rating const

//g++ -std=c++11 sb.cpp