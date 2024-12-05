# Music Recommendation Bot

A C++ application that interacts with the Spotify Web API to fetch personalized music recommendations based on your top tracks or artists. This bot uses cURL for HTTP requests and the JSON for Modern C++ library to parse API responses.

## Features

- Fetch the user's top tracks or artists from Spotify.
- Generate music recommendations based on seed tracks or artists.
- Display recommendations in the terminal.
- Simple and easy-to-use interface.

## Requirements

- C++17 or later
- Spotify Developer Account
- Spotify OAuth Token with the following scopes:
  - `user-top-read`
  - `playlist-read-private`
- Libraries:
  - [cURL](https://curl.se/)
  - [JSON for Modern C++](https://github.com/nlohmann/json)

## Installation

### Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/music-recommendation-bot.git
cd music-recommendation-bot
```

### Step 2: Install Dependencies

#### Linux

```bash
sudo apt update
sudo apt install libcurl4-openssl-dev
```

#### MacOS

```bash
brew install curl
```

#### Windows

- Download and install the [cURL library](https://curl.se/download.html).
- Add the `include` and `lib` directories to your compiler's paths.

#### JSON for Modern C++

1. Download the single-header file [json.hpp](https://github.com/nlohmann/json).
2. Place `json.hpp` in the project directory.

### Step 3: Compile the Project

```bash
g++ -o music_recommendation_bot music_recommendation_bot.cpp -lcurl
```

## Usage

1. Obtain a Spotify OAuth token from the [Spotify Web Console](https://developer.spotify.com/console/).
2. Run the program and enter your token when prompted:

```bash
./music_recommendation_bot
```

3. View your top tracks and personalized recommendations in the terminal.

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Make your changes and commit them (`git commit -m "Add feature-name"`).
4. Push to the branch (`git push origin feature-name`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Spotify Web API](https://developer.spotify.com/documentation/web-api/)
- [cURL Library](https://curl.se/)
- [JSON for Modern C++](https://github.com/nlohmann/json)

---

Feel free to reach out if you have questions or suggestions.

