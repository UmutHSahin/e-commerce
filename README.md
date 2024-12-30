## Project Overview  
This project simulates an online shopping website. The application includes five main classes: `Product`, `Book`, `Movie`, `Music`, and `Cart`. Users interact with the program either as an Admin or as a Customer, each with specific functionalities.  

---  

## Features  
1. **Classes**:  
   - **`Product`**: Base class containing common attributes and methods for all products.  
   - **`Book`**, **`Movie`**, **`Music`**: Specialized classes inheriting from `Product`, each with additional attributes and functionality.  
   - **`Cart`**: Manages product selections and the shopping cart operations.  

2. **Admin Functionalities**:  
   - Update product stock and price.  
   - Access and modify the product database.  

3. **Customer Functionalities**:  
   - View cart contents.  
   - Browse and select products from categories.  
   - Add/remove products to/from the cart.  
   - Confirm the cart to complete an order.  

4. **Object-Oriented Concepts**:  
   - Constructors and Destructors.  
   - Accessor and Mutator Methods.  
   - Method Overloading.  
   - Virtual Methods.  
   - Inheritance.  
   - Template Function.  
   - Operator Overloading.  

---  

## Functional Requirements  

### 1. **Product Class**:  
   - Attributes: `name`, `language`, `genre`, `category`, `stock`, `price`, `product_code`.  
   - Methods:  
     - `display()`: Displays product details.  
     - `calculateDiscount()`: Calculates discounted price based on product type.  
     - `checkStock()`: Checks stock availability.  

### 2. **Specialized Classes**:  
   - **`Book`**:  
     - Additional attributes: `publisher`, `ISBN`.  
     - `display()` method: Prints book-specific details.  
   - **`Music`**:  
     - Additional attributes: `artist`, `format`, `runtime`.  
     - `display()` method: Prints music-specific details.  
   - **`Movie`**:  
     - Additional attributes: `directors` (up to 2), `starring` (up to 3), `subtitles`, `audio_language`.  
     - `display()` method: Prints movie-specific details.  

### 3. **Cart Class**:  
   - Attributes:  
     - `product_list`: List of added products (maximum of 5).  
     - `total_price`: Total price of the cart.  
   - Methods:  
     - Add/remove products to/from the cart.  
     - Display cart contents and total price.  

### 4. **Authorization Levels**:  
   - **Admin**:  
     - Access by entering `"*"`.  
     - Can update product stock and price.  
   - **Customer**:  
     - Access by pressing Enter.  
     - Can view cart, select products, and checkout.  

---  

## Technical Details  

### Login Scenarios:  
1. **Admin**:  
   - Options:  
     - Update product stock and price.  
     - Exit the system.  
2. **Customer**:  
   - Options:  
     - View cart.  
     - Browse products by category.  
     - Exit the system.  

### Cart Management:  
- Limit: Maximum 5 products.  
- Options:  
  - Add products to cart.  
  - Remove products by list number.  
  - Confirm cart for order placement.  
  - Display warning if exiting without confirmation.  

### Template Function:  
- Updates the total cart price based on discounted product prices.  

---  

## Implementation Instructions  
1. **Setup**:  
   - Define and implement the required classes and their methods in the programming language of choice.  
   - Use appropriate OOP principles to structure the code.  

2. **Testing**:  
   - Test all functionalities, including Admin and Customer workflows.  
   - Ensure compliance with the functional requirements.  

3. **Comments**:  
   - Add detailed comments explaining the purpose and operation of classes, methods, and variables.  

---  

## Important Notes  
- **Individual Work**: Complete the project independently. Sharing or copying solutions will result in disqualification.  
- **Compliance**: Follow the project requirements strictly. Any deviation may lead to penalties.  
