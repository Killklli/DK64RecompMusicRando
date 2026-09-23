import io
import os
import random
import zipfile
from Songs import song_data
from SongsEnum import Songs
from SongType import SongType

pack = None
pool_song_names = {}
song_track_cache = {}
seed = random.Random().getrandbits(128)


def get_random_song_data(mods_folder, song_id):
    global pack, pool_song_names, song_track_cache, seed

    song = song_data.get(Songs(song_id))
    if song.type in [SongType.Ambient, SongType.Protected, SongType.System]:
        return None

    songtypes = {
        SongType.BGM: "bgm/",
        SongType.Event: "events/",
        SongType.MajorItem: "majoritems/",
        SongType.MinorItem: "minoritems/",
    }

    if pack is None:
        os.makedirs(mods_folder + "/../mods_data", exist_ok=True)
        pack_path = os.path.join(mods_folder + "/../mods_data", "pack.zip")
        if not os.path.exists(pack_path):
            return None
        pack = zipfile.ZipFile(pack_path)
        pool_song_names = {}
        for folder in songtypes.values():
            pool_song_names[folder] = [track_name for track_name in pack.namelist() if track_name.startswith(folder) and track_name.endswith(".candy")]

    song_type = songtypes[song.type]
    songs = pool_song_names[song_type]
    if not songs:
        return None

    if song_id not in song_track_cache:
        song_track_cache[song_id] = random.Random(seed + song_id).choice(songs)
    track_name = song_track_cache[song_id]
    with pack.open(track_name) as track_file:
        candy_bytes = track_file.read()
    with zipfile.ZipFile(io.BytesIO(candy_bytes)).open("song.bin") as song_file:
        song_bytes = song_file.read()
        return song_bytes
