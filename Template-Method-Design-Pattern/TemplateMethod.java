// Author - Given Lepita


/* 

* The code defines an abstract class called CookingRecipe, which acts as the template for cooking different recipes.
* It provides a template method cookRecipe() that outlines the basic cooking steps for any recipe.
* The template method is declared as final, indicating that subclasses cannot override it.

* The CookingRecipe class also declares two abstract methods: prepareIngredients() and cook().
* These methods are meant to be implemented by the concrete subclasses to define the specific steps for preparing ingredients and cooking a particular recipe.

* The CookingRecipe class also provides a default implementation for the serve() method, which is a common step in serving any dish.
* This method can be optionally overridden by subclasses if they require specific serving instructions.

* The code includes two concrete subclasses: PizzaRecipe and PastaRecipe.
* Each subclass extends the CookingRecipe class and provides its own implementation for the abstract methods prepareIngredients() and cook().
* They can also override the serve() method if needed.

* In the TemplateMethod class (the client code), the main() method creates instances of the PizzaRecipe and PastaRecipe subclasses and calls the cookRecipe() method on each instance.
* This triggers the template method defined in the abstract CookingRecipe class, executing the steps in the defined order.

*************************************************************************************************************************************************************
By utilizing the Template Method design pattern, the code promotes code reuse and provides a common structure for cooking recipes.
The abstract class defines the overall template and skeleton of the cooking process, while the concrete subclasses implement the specific steps for individual recipes.
This allows for flexibility and customization while adhering to a consistent cooking process.
*************************************************************************************************************************************************************


*/

// Abstract class defining the template method and the basic cooking steps
abstract class CookingRecipe {
    
    // Template method that defines the cooking process
    public final void cookRecipe() {
        prepareIngredients();
        cook();
        serve();
    }
    
    // Abstract methods to be implemented by subclasses
    protected abstract void prepareIngredients();
    protected abstract void cook();
    
    // Default implementation for serving
    protected void serve() {
        System.out.println("Serve the dish.");
    }
}

// Concrete subclass implementing the cooking recipe for Pizza
class PizzaRecipe extends CookingRecipe {
    
    @Override
    protected void prepareIngredients() {
        System.out.println("Gather pizza dough, sauce, cheese, and toppings.");
    }
    
    @Override
    protected void cook() {
        System.out.println("Roll out the dough, spread the sauce, add cheese and toppings, and bake in the oven.");
    }
    
    // Optional: Override the serve method if needed
}

// Concrete subclass implementing the cooking recipe for Pasta
class PastaRecipe extends CookingRecipe {
    
    @Override
    protected void prepareIngredients() {
        System.out.println("Boil water, gather pasta, and prepare sauce.");
    }
    
    @Override
    protected void cook() {
        System.out.println("Cook the pasta in boiling water, drain it, mix it with the sauce, and simmer for a while.");
    }
    
    @Override
    protected void serve() {
        System.out.println("Serve the pasta with grated cheese and parsley.");
    }
}

// Client code
public class TemplateMethod {
    public static void main(String[] args) {
        CookingRecipe pizzaRecipe = new PizzaRecipe();
        pizzaRecipe.cookRecipe();
        
        System.out.println();
        
        CookingRecipe pastaRecipe = new PastaRecipe();
        pastaRecipe.cookRecipe();
    }
}
