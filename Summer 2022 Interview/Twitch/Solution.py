def solution(streamerInformation, commands):
    streamers = {}
    result = []

    for i in range(0, len(streamerInformation), 3):
        streamers[streamerInformation[i]] = (int(streamerInformation[i + 1]), streamerInformation[i + 2])

    i = 0
    while i < len(commands):
        c = commands[i]
        print(c)

        if c == "StreamerOnline":
            print("StreamerOnline")
            name = commands[i + 1]
            views = int(commands[i + 2])
            category = commands[i + 3]
            streamers[name] = (views, category)

            i += 4
            continue

        if c == "UpdateViews":
            name = commands[i + 1]
            views = int(commands[i + 2])
            category = streamers[name][1]
            streamers[name] = (views, category)

            i += 4
            continue

        if c == "UpdateCategory":
            name = commands[i + 1]
            views = streamers[name][0]
            old_category = commands[i + 2]
            new_category = commands[i + 3]
            if streamers[name][1] == old_category:
                streamers[name] = (views, new_category)

            i += 4
            continue

        if c == "StreamerOffline":
            name = commands[i + 1]
            if (commands[i + 2] == streamers[name][1]):
                del (streamers[name])

            i += 3
            continue

        if c == "ViewsInCategory":
            category = commands[i + 1]
            total = 0
            for s in streamers:
                if streamers[s][1] == category:
                    total += streamers[s][0]
            result.append(total)

            i += 2
            continue

        if c == "TopStreamerInCategory":
            category = commands[i + 1]
            name = ""
            views = 0
            for s in streamers:
                if streamers[s][1] == category and streamers[s][0] >= views:
                    views = streamers[s][0]
                    name = s

            if name == "":
                result.append(None)
            else:
                result.append(name)

            i += 2
            continue

        if c == "TopStreamer":
            name = ""
            views = 0
            for s in streamers:
                if streamers[s][0] >= views:
                    views = streamers[s][0]
                    name = s
            result.append(name)
            i += 1
            continue
    return result


if __name__ == "__main__":
    init = ["Ninja", "100000", "Fortnite", "Pokimane", "40000", "Valorant"]
    commands = ["UpdateViews", "Ninja", "120000", "Fortnite", "ViewsInCategory", "Fortnite"]
    print(solution(init, commands))
