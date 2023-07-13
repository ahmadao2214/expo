import { DeviceEventEmitter } from 'expo-modules-core';
import { EventEmitter, EventSubscription } from 'fbemitter';
import { useEffect, useRef } from 'react';

import { UseUpdatesEvent } from './UseUpdates.types';

// Emitter and hook specifically for @expo/use-updates module

let _emitter: EventEmitter | null;

function _getEmitter(): EventEmitter {
  if (!_emitter) {
    _emitter = new EventEmitter();
  }
  return _emitter;
}

function _addListener(listener: (event: UseUpdatesEvent) => void): EventSubscription {
  const emitter = _getEmitter();
  return emitter.addListener('Expo.useUpdatesEvent', listener);
}

// What JS code uses to emit events
export const emitEvent = (event: UseUpdatesEvent) => {
  if (!_emitter) {
    throw new Error(`EventEmitter must be initialized to use from its listener`);
  }
  _emitter.emit('Expo.useUpdatesEvent', event);
};

export const useUpdateEvents = (listener: (event: UseUpdatesEvent) => void) => {
  const listenerRef = useRef<typeof listener>();

  useEffect(() => {
    listenerRef.current = listener;
  }, [listener]);

  useEffect(() => {
    if (listenerRef.current) {
      const subscription = _addListener(listenerRef.current);
      return () => {
        subscription.remove();
      };
    }
    return undefined;
  }, []);
};
