/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
use std::cmp::Ordering;
use std::io::{self, Write};

#[derive(Debug, Clone)]
struct Movie {
    name: String,
    director: String,
    genre: String,
    price: f32,
    rating: f32, // 0.0–5.0
}

impl Movie {
    fn new(name: &str, director: &str, genre: &str, price: f32, rating: f32) -> Self {
        Self {
            name: name.to_string(),
            director: director.to_string(),
            genre: genre.to_string(),
            price,
            rating,
        }
    }
}

fn seed_data() -> Vec<Movie> {
    vec![
        Movie::new("Mad Max: Fury Road", "George Miller", "Action", 8.49, 4.7),        // 2015
        Movie::new("The Social Network", "David Fincher", "Drama", 6.99, 4.5),        // 2010
        Movie::new("Guardians of the Galaxy", "James Gunn", "Sci-Fi", 7.49, 4.3),    // 2014
        Movie::new("Inside Out", "Pete Docter", "Animation", 5.99, 4.6),              // 2015

        Movie::new("Skyfall", "Sam Mendes", "Action", 7.99, 4.4),                     // 2012
        Movie::new("Spectre", "Sam Mendes", "Action", 9.49, 4.0),                    // 2015

        Movie::new("Coco", "Lee Unkrich", "Animation", 6.49, 4.7),                   // 2017
        Movie::new("Toy Story 3", "Lee Unkrich", "Animation", 6.99, 4.8),            // 2010

        Movie::new("The Shape of Water", "Guillermo del Toro", "Fantasy", 8.49, 4.2), // 2017
        Movie::new("Pacific Rim", "Guillermo del Toro", "Sci-Fi", 6.49, 4.0),         // 2013

        Movie::new("Black Panther", "Ryan Coogler", "Action", 9.99, 4.6),            // 2018
        Movie::new("Creed", "Ryan Coogler", "Sports", 5.99, 4.4),                     // 2015
    ]
}


fn prompt(label: &str) -> String {
    print!("{label}");
    let _ = io::stdout().flush();
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("read_line failed");
    buf.trim().to_string()
}

/// Parses an optional string field: empty or "none" -> None, else Some(lowercased)
fn parse_opt_str(input: &str) -> Option<String> {
    let s = input.trim();
    if s.is_empty() || s.eq_ignore_ascii_case("none") {
        None
    } else {
        Some(s.to_string())
    }
}

/// Parses an optional f32 number with a default of None on empty/none.
fn parse_opt_f32(input: &str) -> Option<f32> {
    let s = input.trim();
    if s.is_empty() || s.eq_ignore_ascii_case("none") {
        None
    } else {
        match s.parse::<f32>() {
            Ok(v) => Some(v),
            Err(_) => {
                println!("  (! ) Invalid number \"{s}\", ignoring this criterion.");
                None
            }
        }
    }
}

#[derive(Copy, Clone)]
enum SortKey {
    Name,
    Director,
    Genre,
    Price,
    Rating,
}

fn parse_sort_key(s: &str) -> Option<SortKey> {
    match s.to_ascii_lowercase().as_str() {
        "name" => Some(SortKey::Name),
        "director" => Some(SortKey::Director),
        "genre" => Some(SortKey::Genre),
        "price" => Some(SortKey::Price),
        "rating" => Some(SortKey::Rating),
        _ => None,
    }
}

fn sort_movies(movies: &mut [Movie], key: SortKey) {
    movies.sort_by(|a, b| {
        let ord = match key {
            SortKey::Name => a.name.to_lowercase().cmp(&b.name.to_lowercase()),
            SortKey::Director => a.director.to_lowercase().cmp(&b.director.to_lowercase()),
            SortKey::Genre => a.genre.to_lowercase().cmp(&b.genre.to_lowercase()),
            SortKey::Price => a.price.partial_cmp(&b.price).unwrap_or(Ordering::Equal),
            SortKey::Rating => b.rating.partial_cmp(&a.rating).unwrap_or(Ordering::Equal), // default: higher rating first
        };
        // Stable secondary keys to make ranking feel consistent:
        if ord == Ordering::Equal {
            b.rating
                .partial_cmp(&a.rating)
                .unwrap_or(Ordering::Equal)
                .then_with(|| a.price.partial_cmp(&b.price).unwrap_or(Ordering::Equal))
                .then(a.name.to_lowercase().cmp(&b.name.to_lowercase()))
        } else {
            ord
        }
    });
}

fn print_results(movies: &[Movie]) {
    println!("\n== Recommendations ({}) ==", movies.len());
    if movies.is_empty() {
        println!("No movies matched your criteria.\n");
        return;
    }
    for (i, m) in movies.iter().enumerate() {
        println!(
            "{:>2}. {:<28} | {:<20} | {:<10} | ${:<5.2} | {:.1}",
            i + 1,
            m.name,
            m.director,
            m.genre,
            m.price,
            m.rating
        );
    }
    println!();
}

fn main() {
    println!("Knowledge-Based Movie Recommender (Rust)");
    println!("Enter values or type 'none' (or leave blank) to skip a filter.\n");

    let all_movies = seed_data();
    loop {
        // 1) Gather criteria
        let director_in = prompt("Director (exact match, e.g., Christopher Nolan) [none]: ");
        let genre_in = prompt("Genre (e.g., Sci-Fi, Drama) [none]: ");
        let max_price_in = prompt("Max price (e.g., 9.99) [none]: ");
        let min_rating_in = prompt("Min rating 0.0–5.0 (e.g., 4.2) [none]: ");

        let sort_in = prompt("Sort by (name/director/genre/price/rating) [rating]: ");

        let director = parse_opt_str(&director_in);
        let genre = parse_opt_str(&genre_in);
        let max_price = parse_opt_f32(&max_price_in);
        let min_rating = parse_opt_f32(&min_rating_in);

        let sort_key = parse_sort_key(&sort_in).unwrap_or(SortKey::Rating);

        // 2) Filter imperatively
        let mut results: Vec<Movie> = Vec::new();
        for m in &all_movies {
            if let Some(ref d) = director {
                if !m.director.eq_ignore_ascii_case(d) {
                    continue;
                }
            }
            if let Some(ref g) = genre {
                if !m.genre.eq_ignore_ascii_case(g) {
                    continue;
                }
            }
            if let Some(p) = max_price {
                if m.price > p {
                    continue;
                }
            }
            if let Some(r) = min_rating {
                if m.rating < r {
                    continue;
                }
            }
            results.push(m.clone());
        }

        // 3) Rank/Sort by chosen attribute
        sort_movies(&mut results, sort_key);

        // 4) Display
        print_results(&results);

        // 5) Loop (imperative control flow)
        let again = prompt("Search again? (y/n): ");
        if !again.eq_ignore_ascii_case("y") && !again.eq_ignore_ascii_case("yes") {
            println!("Goodbye!");
            break;
        }
        println!();
    }
}
