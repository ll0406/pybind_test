import numpy as np

def naive_thresh_approach(cam49, cam67, cam68, threshold=253):

    new_frames = []

    # number of frames check
    if not len(cam49) == len(cam67) == len(cam68):
        raise "number of frames mismatch"

    for i in range(len(cam49)):
        high_im = cam49[i]
        over_exp_mask = (high_im > (np.ones(high_im.shape) * threshold)).astype(int)
        high_im = high_im * (1-over_exp_mask) + cam68[i] * over_exp_mask

        over_exp_mask = (high_im > (np.ones(high_im.shape) * threshold)).astype(int)
        high_im = high_im * (1-over_exp_mask) + cam67[i] * over_exp_mask

        new_frames.append(high_im)

    return np.array(new_frames)


def naive_thresh(frame, low_thresh=20, high_thresh=253):
    '''

    :param frame: 2-D np array
    :param low_thresh: int
    :param high_thresh: int
    :return: exposure change
    '''
    over = (frame > high_thresh).astype('int')
    under = -(frame < low_thresh).astype('int')
    return over + under


def naive_thresh_list(frame, low_thresh=20, high_thresh=253):
    '''

    :param frame: list
    :param low_thresh: int
    :param high_thresh: int
    :return: exposure change
    '''
    f = np.array(frame)
    over = (f > high_thresh).astype('int')
    under = -(f < low_thresh).astype('int')
    r = (over + under).tolist()
    # print(r)
    return r

def simple_print():
    """
    Simple print that returns hello world

    Args:
        None

    Returns:
        None
    """
    print("HELLO WORLD in PY")
    return 0
