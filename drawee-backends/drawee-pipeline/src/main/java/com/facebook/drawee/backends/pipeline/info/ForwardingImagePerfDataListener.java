/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

package com.facebook.drawee.backends.pipeline.info;

import com.facebook.infer.annotation.Nullsafe;
import java.util.Collection;

@Nullsafe(Nullsafe.Mode.STRICT)
public class ForwardingImagePerfDataListener implements ImagePerfDataListener {

  private final Collection<ImagePerfDataListener> mListeners;

  public ForwardingImagePerfDataListener(Collection<ImagePerfDataListener> listeners) {
    mListeners = listeners;
  }

  @Override
  public void onImageLoadStatusUpdated(
      ImagePerfData imagePerfData, @ImageLoadStatus int imageLoadStatus) {
    for (ImagePerfDataListener listener : mListeners) {
      listener.onImageLoadStatusUpdated(imagePerfData, imageLoadStatus);
    }
  }

  @Override
  public void onImageVisibilityUpdated(
      ImagePerfData imagePerfData, @VisibilityState int visibilityState) {
    for (ImagePerfDataListener listener : mListeners) {
      listener.onImageVisibilityUpdated(imagePerfData, visibilityState);
    }
  }
}
