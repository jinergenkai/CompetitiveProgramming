struct Creature {
    animal_type: String, 
    name: i32, 
    legs: i32, 
    weapon: String,
}
fn main() {
    let mut _ferris = Creature {
        animal_type: String::from("crab"),
        name: 1,
        legs: 10,
        weapon: String::from("claw"),
    };
    println!("Hello, world!"); 
}
