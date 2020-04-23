class NoneValueError(ValueError):
    pass


def filter_ch(value, filter_ch_list):
    if not value:
        raise NoneValueError("value is None: %s" % value)

    for ch in filter_ch_list:
        if ch == " ":
            value = " ".join(value.split())
        value = value.replace(ch, "")
    return value