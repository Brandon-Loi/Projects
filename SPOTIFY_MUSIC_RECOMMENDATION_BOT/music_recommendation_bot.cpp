/*This bot was made by Brandon Loi as a project.
   The purpose of this bot is to simulate how Spotify would externally recommend you music.
   Thank you to my friends for giving me suggestions on starting this.
   
   This Bot uses the cURL lib and json.hpp lib 
   cURL can be found here @ :https://curl.se/
   json.hpp can be found here @ :https://github.com/nlohmann/json/tree/develop
   credits to @nlohmann for the GOATED json lib*/

#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <Dependencies/nlohmann/json.hpp>

using json = nlohmann::json;

// Callback for cURL write function
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
    size_t totalSize = size * nmemb;
    userData->append((char*)contents, totalSize);
    return totalSize;
}

// Function to perform a GET request
std::string performGET(const std::string& url, const std::string& token) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + token).c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

// Fetch user's top tracks or artists
std::vector<std::string> getTopItems(const std::string& type, const std::string& token) {
    std::string url = "https://api.spotify.com/v1/me/top/" + type + "?limit=5";
    std::string response = performGET(url, token);

    json jsonResponse = json::parse(response);
    std::vector<std::string> topItems;

    for (const auto& item : jsonResponse["items"]) {
        topItems.push_back(item["name"]);
    }

    return topItems;
}

// Fetch recommendations based on seed tracks or artists
std::vector<std::string> getRecommendations(const std::string& seed, const std::string& type, const std::string& token) {
    std::string url = "https://api.spotify.com/v1/recommendations?seed_" + type + "=" + seed;
    std::string response = performGET(url, token);

    json jsonResponse = json::parse(response);
    std::vector<std::string> recommendations;

    for (const auto& track : jsonResponse["tracks"]) {
        recommendations.push_back(track["name"]);
    }

    return recommendations;
}

int main() {
    std::string token;
    std::cout << "Enter your Spotify OAuth token: ";
    std::getline(std::cin, token);

    if (token.empty()) {
        std::cerr << "Error: Token is required to proceed." << std::endl;
        return 1;
    }

    std::cout << "Fetching your top tracks...\n";
    std::vector<std::string> topTracks = getTopItems("tracks", token);

    if (topTracks.empty()) {
        std::cerr << "Could not fetch top tracks. Ensure the token has the correct permissions." << std::endl;
        return 1;
    }

    std::cout << "Your Top Tracks:\n";
    for (const auto& track : topTracks) {
        std::cout << "- " << track << std::endl;
    }

    std::cout << "\nFetching recommendations based on the first track...\n";
    std::vector<std::string> recommendations = getRecommendations(topTracks[0], "tracks", token);

    if (recommendations.empty()) {
        std::cerr << "Could not fetch recommendations." << std::endl;
        return 1;
    }

    std::cout << "Recommended Tracks:\n";
    for (const auto& rec : recommendations) {
        std::cout << "- " << rec << std::endl;
    }

    return 0;
}
