#include <iostream>
#include <list>

// Author - Given Lepita
/* 
                                                    Description - Observer Design Pattern

    -> Defines two classes to showcase a use for the Observer design pattern in terms of an auction.
    -> The AuctionItem class represents an item being auctioned. It has the following attributes:

        itemName: A string representing the name of the auction item.
        currentBid: A double representing the current highest bid for the item.
        bidders: A list of pointers to Bidder objects representing the registered bidders interested in this item. 

    -> The AuctionItem class has the following methods:
        
        attach: Adds a bidder to the list of bidders interested in the item.
        detach: Removes a bidder from the list of interested bidders.
        setBid: Sets a new bid for the item. If the new bid is higher than the current highest bid, it updates the current bid and notifies all registered bidders.
        notifyBidders: Notifies all registered bidders by calling their update method and passing the new highest bid as a parameter.
    
    -> The Bidder class represents a bidder interested in the auction item. It has the following attribute:

        bidderName: A string representing the name of the bidder.
    
    -> The Bidder class has a single method:

        update: Receives an update from the auction item with the new highest bid and prints a message indicating the bidder's name and the current highest bid.

    -> main function:

        An instance of AuctionItem is created with the name "Painting".
        Two instances of Bidder are created with names "Given" and "Lepita".
        Both bidders are attached to the auction item using the attach method.
        The current highest bid is set to 100.0 using the setBid method, and both Given and Lepita receive an update.
        The current highest bid is set to 150.0, and again both Given and Lepita receive an update.
        Lepita is detached from the auction item using the detach method.
        The current highest bid is set to 200.0, and only Given receives an update.
        The program ends with a return statement.

    **** this code demonstrates how the Observer pattern allows multiple bidders (observers) ****
    **** to receive updates from an auction item (subject) when its state (highest bid) changes. ****

*/
class Bidder;  // declaration

// Subject (Observable)
class AuctionItem {
private:
    std::string itemName;
    double currentBid;
    std::list<Bidder*> bidders;

public:
    AuctionItem(const std::string& name) : itemName(name), currentBid(0.0) {}

    void attach(Bidder* bidder) {
        bidders.push_back(bidder);
    }

    void detach(Bidder* bidder) {
        bidders.remove(bidder);
    }

    void setBid(double newBid) {
        if (newBid > currentBid) {
            currentBid = newBid;
            notifyBidders();
        }
    }

    void notifyBidders() {
        for (auto bidder : bidders) {
            bidder->update(currentBid);
        }
    }
};

// Observer
class Bidder {
private:
    std::string bidderName;

public:
    Bidder(const std::string& name) : bidderName(name) {}

    void update(double newBid) {
        std::cout << bidderName << " received an update: Current highest bid is $" << newBid << std::endl;
    }
};

int main() {
    AuctionItem item("Painting");
    Bidder bidder1("Given");
    Bidder bidder2("Lepita");

    item.attach(&bidder1);
    item.attach(&bidder2);

    item.setBid(100.0);  // Given and Lepita will receive an update
    item.setBid(150.0);  // Given and Lepita will receive an update

    item.detach(&bidder2);

    item.setBid(200.0);  // Only Given will receive an update

    return 0;
}
