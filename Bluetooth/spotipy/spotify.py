from flask import Flask, request, url_for, session, redirect
import spotipy
from spotipy.oauth2 import SpotifyClientCredentials


class SpotifyBot():
    def __init__(self):
        client_id = "2590a24f719846b5bca0202a6d738489"
        client_secret = "025fa563fa4048a9a8a404ee817454af"
        redirect_uri = "https://google.com"
        scope = "user-read-playback-state user-modify-playback-state"
        self.device_name = "DESKTOP-CI79GB0"

        oauth = spotipy.oauth2.SpotifyOAuth(client_id=client_id,client_secret=client_secret,redirect_uri=redirect_uri,scope=scope)
        token = oauth.get_access_token()["access_token"]    
        self.bot = spotipy.Spotify(auth=token)

    def get_device_id(self):
        for device in self.bot.devices()["devices"]:
            if device["name"] == self.device_name:
                device_id = device["id"]
        print(f"Device id:{device_id}")
        return device_id
        
    def get_current_track(self):
        current = self.bot.current_user_playing_track()
        track_name =  current["item"]["name"]
        print(f"Current playing:{track_name}")
        return track_name

    def get_current_track_artist(self):
        current = self.bot.current_user_playing_track()
        artist_name = current["item"]["album"]["artists"][0]["name"]
        print(f"Artist name:{artist_name}")
        return artist_name

    def next_track(self):
        print("Skipping...")
        self.bot.next_track()

    def prev_track(self):
        print("Previous track...")
        self.bot.previous_track()

    def pause(self):
        print("Pausing...")
        self.bot.pause_playback()
